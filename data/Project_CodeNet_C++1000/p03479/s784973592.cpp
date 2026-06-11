#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

void ERROR(int num) { printf("ERROR%d!\n",num); }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

ll X, Y;

int main(){
	cin >> X >> Y;

	int cnt = 1;
	ll A = X;
	while(1){
		A *= 2;
		if(A <= Y) cnt++; 
		else break;
	}
	cout << cnt << endl;
}