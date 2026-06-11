#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=1e5;
const int inf=1e9;
int main(){
	string s,t; cin>>s>>t;
	int n = s.size();
	rep(i,0,n){
		bool flag = true;
		rep(j,0,n)if(s[j] != t[(i+j)%n]) flag = false;
		if(flag){ cout<<"Yes"<<endl; return 0; }
	}cout<<"No"<<endl;
}