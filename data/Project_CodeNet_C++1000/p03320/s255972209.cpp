#include<iostream>

using namespace std;

int s(long long x){
	int res = 0;
	while(x > 0){
		res += x % 10;
		x /= 10;
	}
	return res;
}

long long next_sunuke(long long x){
	if(x < 10){
		return x;
	}
	long long t = x, k = 10;
	double sunuke1, sunuke2;
	sunuke1 = 1.0 * x / s(x);
	while(k <= x){
		t = t - (t % k) + (k - 1);
		sunuke2 = 1.0 * t / s(t);
		if(sunuke1 > sunuke2){
			x = t;
			sunuke1 = sunuke2;
		}else{
			break;
		}
		k *= 10;
	}
	return x;
}

int main(){
	int k, ans = 0;
	cin >> k;
	long long t = 1;
	for(int i = 1; i <= k; i++){
		cout << t << endl;
		t = next_sunuke(t + 1);
	}
	return 0;
}