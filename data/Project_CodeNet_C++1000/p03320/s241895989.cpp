#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=1050;
//ここまでテンプレ
//↓10進数でi桁目の数を取り出すセット
unsigned long long deci[20]={1};
//iは0-indexedなので注意！
int deciBit(long long N,int i){
	N/=deci[i];
	return (int)(N%10);
}
//N以上で最小のすぬけ数を求める
ll Snuke(ll N){
	stringstream SS;
	SS<<N;
	string S=SS.str();
	double mini=1.*INFLL*INFLL*INFLL;
	ll snuke=N;
	for(int i=0;i<S.length();i++){
		for(int j=S[i]-'0';j<=9;j++){
			string T=S;
			for(int k=0;k<S.length();k++)
				if(k==i)
					T[k]=j+'0';
				else if(k>i)
					T[k]='9';
			ll M=stoll(T);
			ll ds=0;
			for(int k=0;k<20;k++)
				ds+=deciBit(M,k);
			double temp=1.*M/ds;
			if(mini>temp){
				mini=temp;
				snuke=M;
			}
		}
	}
	return snuke;
}
int main(){
	for(int i=1;i<20;i++){
		deci[i]=deci[i-1]*10;
	}
	int K;
	cin>>K;
	ll N=1;
	for(int i=0;i<K;i++){
		cout<<N<<endl;
		N=Snuke(N+1);
	}
	return 0;
}