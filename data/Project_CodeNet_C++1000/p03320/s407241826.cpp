#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <climits>

#define REP(i,n) for(int i=0;i<int(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define show(x) cout<< #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,ll> pdl;

int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};
int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}	

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int N_MAX=100010;

ll calc(ll n){
	ll res=0;
	while(n>0){
		res+=n%10;
		n/=10;
	}
	return res;
}

int main(){
	ll k;
	cin>>k;
	vector<pdl> v;
	for(int i=1;i<=99;i++){
		v.pb(pdl((double)i/calc(i),i));
	}
	for(int d=3;d<=15;d++){
		ll n=0;
		for(int i=0;i<d-3;i++){
			n+=9*pow(10,i);
		}
		ll temp=n;
		for(int i=100;i<=999;i++){
			n=temp;
			n+=i*pow(10,d-3);
			v.pb(pdl((double)n/calc(n),n));
		}
	}
	sort(ALL(v));
	ll mn=10000000000000000;
	for(int i=0;i<v.size();i++){
		for(int j=i;j<v.size();j++){
			if(v[i].second>v[j].second){
				v[j].second=-1;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<v.size();i++){
		if(v[i].second!=-1){
			//cout<<v[i].first<<" "<<v[i].second<<endl;
			cout<<v[i].second<<endl;
			cnt++;
		}
		if(cnt==k)break;
	}
	return 0;
}
