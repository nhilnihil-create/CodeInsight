#include <bits/stdc++.h>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
#define fcout cout<<fixed<<setprecision(10)
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

int main(){
	string s; cin>>s;
	int count[3]={};
	FOR(i,0,s.size()){
		count[s[i]-'a']++;
	}
	int flag=true;
	int giri=s.size()%3;
	if(!giri)giri+=3;
	int giri2=0;
	FOR(i,0,3){
		if(count[i]>(s.size()+2)/3) flag=false;
		if(count[i]==(s.size()+2)/3) giri2++;
	}
	if(giri2>giri) flag=false;
	YES(flag);
}