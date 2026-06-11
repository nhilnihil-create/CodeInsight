#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=998244353;
const int size=2e5+1;
const int inf=1e9;
int main(){
	int H,W,N; cin>>H>>W>>N;
	int x,y; cin>>x>>y; x--; y--;
	string s,t; cin>>s>>t;
	int a = y, b = y, c = x, d = x;
	rep(i,0,N){
		if(s[i] == 'L') a--;
		else if(s[i] == 'R') b++;
		else if(s[i] == 'U') c--;
		else if(s[i] == 'D') d++;
		if(a < 0 || b >= W || c < 0 || d >= H){ cout<<"NO"<<endl; return 0; }
		if(t[i] == 'L' && b > 0) b--;
		else if(t[i] == 'R' && a < W-1) a++;
		else if(t[i] == 'U' && d > 0) d--;
		else if(t[i] == 'D' && c < H-1) c++;
	}cout<<"YES"<<endl;
}