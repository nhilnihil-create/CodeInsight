#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N;
	map<pair<string,string>,ll> pattern;
	string Skari;
	string S;
	ll ans=0;
	scan(N);scan(Skari);
	rep(i,N) S[i]=Skari[i];
	for(int i=N;i<2*N;i++) S[i]=Skari[3*N-i-1];
	ll bitmax=(1LL<<N);
	rep(i,bitmax){
		string s="";
		string t="";
		rep(j,N){
			if(((i>>j)&1)){
				s+=S[j];
			}
			else{
				t+=S[j];
			}
		}
		pattern[mp(s,t)]++;
	}
	rep(i,bitmax){
		string s="";
		string t="";
		rep(j,N){
			if(((i>>j)&1)){
				s+=S[j+N];
			}
			else{
				t+=S[j+N];
			}
		}
		ans+=pattern[mp(s,t)];
	}
	prin(ans);
	return 0;
}
