#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=1005;
const int MOD=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())

int H,W,N,X0,Y0,X1,Y1,X2,Y2;
string S,T;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>H>>W>>N>>X0>>Y0>>S>>T;
	X1=1;X2=H;Y1=1;Y2=W;
	DEC(i,N-1,0){
		if(T[i]=='D')X1--;
		if(T[i]=='U')X2++;
		if(T[i]=='L')Y2++;
		if(T[i]=='R')Y1--;
		X1=max(X1,1);
		X2=min(X2,H);
		Y1=max(Y1,1);
		Y2=min(Y2,W);
		if(S[i]=='U')X1++;
		if(S[i]=='D')X2--;
		if(S[i]=='R')Y2--;
		if(S[i]=='L')Y1++;
		if(X1>X2||Y1>Y2){
			cout<<"NO\n";
			return 0;
		}
		X1=max(X1,1);
		X2=min(X2,H);
		Y1=max(Y1,1);
		Y2=min(Y2,W);
	}
	if(X1<=X0&&X0<=X2&&Y1<=Y0&&Y0<=Y2)cout<<"YES\n";
	else cout<<"NO\n";
}
/*
3
2 5
6 1
3 7
Ans:6

4
3 7
2 9
8 16
10 8
Ans:9
*/
