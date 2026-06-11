
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
ll inf = (1LL << 50);

//bool operator< (pint a, pint b) {
	//return a.second < b.second;

//}



ll gcd(ll a, ll b) {

	if (b == 0)
		return a;

	return gcd(b, a % b);


}

ll max(ll a, ll b) {
	if (a < b) {
		return b;
	}
	else
		return a;

}

ll min(ll a, ll b) {
	if (a < b)
		return a;

	return b;
}




pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pint> list;








float t[1000], v[1000], minv[1000];

int main() {
	ll N;

	ll sum_t = 0;
	cin >> N;

	rep(i, N) {
		cin >> t[i + 1];

	}
	rep(i, N)
		cin >> v[i+1];



	for (int i = N+1; i >= 0; i--) {
		
		if (minv[i] > v[i - 1]) {

			minv[i - 1] = v[i - 1];
		}
		else {

			minv[i - 1] = min(v[i - 1], minv[i] + t[i-1]);

		}

	}

	float nowv = 0;
	float sum = 0;
	for(int i = 1; i <= N; i++){


	


		if (minv[i + 1] >= minv[i]) {
			float s = (float)min(t[i], minv[i] - nowv);

			sum += s * (2.0 * nowv + s) / 2.0 + (t[i] - s) * minv[i];

		
			nowv = nowv + s;
		}


		else {
			float vel = (nowv + minv[i+1] + t[i]) / 2;


			if (minv[i + 1] - nowv > t[i]) {

				sum += (nowv + nowv + t[i]) * t[i] / 2;

				nowv = nowv + t[i];
			}
			
			else {

				sum += (vel + nowv) * (vel - nowv) / 2 + (minv[i + 1] + vel) * (t[i] - (vel - nowv)) / 2;


				if (vel > minv[i]) {

					sum -= (vel - minv[i]) * (t[i] - minv[i] + minv[i + 1] - minv[i] + nowv) / 2;
					
				}

				nowv = minv[i + 1];

			}
			

			
		}


	}
	
	
	printf("%f\n", sum);



	return 0;
}