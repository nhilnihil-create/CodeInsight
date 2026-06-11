#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
string s;
ll n;
string sub_string(int i,int j){
	string t;
	for(int k=0;k<i;k++)t+=s[k];
	for(int k=j+1;k<n;k++)t+=s[k];
	return t;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>s;n=s.size();
	if(n<7){
		cout<<"NO";
		return 0;
	}
	if(s=="keyence"){
		cout<<"YES";
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(sub_string(i,j)=="keyence"){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}
