#include <iostream>
#include <string>
using namespace std;
double speed(double a);

double t_time = 0.0;
int N, t[100], v[100];
int main(void) {
	double distance = 0.0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		t_time += t[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (double i = 0.0; i < t_time; i += 0.5) {
		distance += 0.25 * (speed(i) + speed(i + 0.5));
	}
	printf("%lf", distance);

	return 0;
}
double speed(double x) {
	double f[102], t_t = 0, f_tmp;
	f[0] = x;
	f_tmp = f[0];
	f[1] = t_time - x;
	if (f_tmp > f[1])	f_tmp = f[1];
	for (int i = 0; i < N; i++) {
		t_t += t[i];
		if (t_t - t[i] >= x) {
			f[i + 2] = v[i] + (t_t - t[i] - x);
		}
		else if (t_t - t[i] < x && t_t >= x) {
			f[i + 2] = v[i];
		}
		else if (t_t < x) {
			f[i + 2] = v[i] + (x - t_t);
		}
		if (f_tmp > f[i + 2])	f_tmp = f[i + 2];
	}
	return f_tmp;
}