#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
//ユークリッド
ll gcd(ll a,ll b){
	ll t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	if(a%b==0)return b;
	return gcd(b,a%b);
}
//階乗
ll Factorial(ll a){
	ll b=1;
	for(ll i=a;i>=1;i--){
		b=b*i;
	}
	return b;
}
//素数判定
bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	ll N,K;
	vector<ll>H,ANS;
	cin>>N>>K;
	rep(i,N){
		ll t;
		cin>>t;
		H.push_back(t);
	}
	sort(H.begin(),H.end());
	for(ll i=0;i<N-K+1;i++){
		ll t;
		t=H[i+K-1]-H[i];
		ANS.push_back(t);
	}
	sort(ANS.begin(),ANS.end());
	cout<<ANS.front()<<endl;
}