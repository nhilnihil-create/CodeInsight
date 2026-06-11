#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)
long long gcd(long long a,long long b){ return b ? gcd(b,a%b) : a; }
long long lcm(long long a,long long b){ return a * b / gcd(a, b); }
 
 
int main(){
	long long N,M;
	cin >> N >> M;
	string S,T;
	cin >> S >> T;
	long long L = lcm(N,M);
	long long G = gcd(N,M);
	long long s = N / G;
	long long t = M / G;
	for(long long i = 0;i < L; i++){
		//cout << i*s << "=" << S[i*s] << " " << i*t << "=" << T[i*t] << endl;
		if(i*s >= N || i*t >= M) break;
		if(S[i*s] != T[i*t]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << L << endl;
    return 0;
}