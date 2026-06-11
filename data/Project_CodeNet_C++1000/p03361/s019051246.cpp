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
	ll H,W;
	string ANS="Yes";
	cin>>H>>W;
	vector<vector<char>>V(H+2,vector<char>(W+2,'.'));
	for(ll i=1;i<=H;i++){
		for(ll j=1;j<=W;j++){
			char t;
			cin>>t;
			V[i][j]=t;
		}
	}
	for(ll i=1;i<=H;i++){
		for(ll j=1;j<=W;j++){
			if(V[i][j]=='#'&&V[i+1][j]!='#'&&V[i-1][j]!='#'&&V[i][j-1]!='#'&&V[i][j+1]!='#'){
				ANS="No";
			}
		}
	}
	cout<<ANS<<endl;
}