// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

bool vst[1<<20];


int main(){	
	int m,k;cin>>m>>k;
	vector<int>t;
	int lim=1<<m;
	if(k>=lim){
		cout<<"-1"<<endl;
		return 0;
	}
	if(m==1&&k==1){
		cout<<"-1"<<endl;
		return 0;
	}
	if(m==0&&k==0){
		cout<<"0 0"<<endl;
		return 0;
	}
	if(k==0){
		For(i,0,lim)cout<<i<<" "<<i<<" ";
		cout<<endl;
		return 0;
	}

	For(i,0,lim)if(!vst[i]){
		t.pb(i);
		t.pb(i^k);
		vst[i]=true;
		vst[i^k]=true;
	}
	For(i,0,sz(t))cout<<t[i]<<" ";
	for(int i=0;i<lim;i+=2)
		swap(t[i],t[i+1]);
	For(i,0,sz(t))cout<<t[i]<<" ";
	cout<<endl;
	
	return 0;
}
