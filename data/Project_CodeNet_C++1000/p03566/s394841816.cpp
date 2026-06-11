#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> t(N), v(N);
  for (int i = 0; i < N; i++) cin >> t[i];
  for (int i = 0; i < N; i++) cin >> v[i];

  t.insert(t.begin(), 0);
  for (int i = 0; i < N; i++) t[i+1] += t[i];
  t.insert(t.begin(), 0);
  t.insert(t.end(), t.back());

  v.insert(v.begin(), 0);
  v.insert(v.end(), 0);

  double prevSpeed = 0, ans = 0;
  for (double time = 0.5; time <= t.back(); time += 0.5) {
    double speed = 100;
    for (int i = 0; i <= N+1; i++) {
      if (time < t[i])
        speed = min(speed, v[i] + (t[i] - time));
      else if (time > t[i+1])
        speed = min(speed, v[i] + (time - t[i+1]));
      else
        speed = min(speed, v[i]);
    }
    ans += 0.25 * (prevSpeed + speed);
    prevSpeed = speed;
  }
  cout << fixed << setprecision(3) << ans << endl;
}