#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)

string s;
string ss[10];
string S[25005];
map<string,ll> mp;
ll K;
ll n;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>s>>K;

ll n=0; 
ll sz=s.size();
rep(i,sz){
	ss[0]=s.substr(i,1);
	ss[1]=s.substr(i,2);
	ss[2]=s.substr(i,3);
	ss[3]=s.substr(i,4);
	ss[4]=s.substr(i,5);

	rep(k,5){
		if(i+k>=sz) continue;
		if(mp[ss[k]]==0){
		S[n]=ss[k]; n++;
		mp[ss[k]]++;
		}
	}
}


sort(S,S+n);

cout<<S[K-1]<<endl;

}
	
