#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((LL)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

int main(){
	string str;
	int N;
	cin >> str;
	N = str.size();
	map<char, int> m;
	foreach(i, str){
		++m[i];
	}
	foreach(i, m){
		if((i.second-1)*2+i.second > N){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
