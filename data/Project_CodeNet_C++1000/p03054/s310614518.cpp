#include<bits/stdc++.h> 
using namespace std; 
//python interactive_runner.py python3 local_testing_tool.py 0 -- ./Code
 
#define x first
#define y second
#define rep(i, a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i,b) for(int i = 0; i < int(b); ++i)
typedef pair<int, int> pii;
int H,W,N,x,y;
const int MAXN = 200000+13;
char S[MAXN],T[MAXN];
const int MAXH = 1000+6;
char grid[MAXH][MAXH];
void solve(){
   
   cin>>H>>W>>N>>x>>y>>S>>T;
   pair<int,int> u = make_pair(0,H-1);
   pair<int,int> r = make_pair(0,W-1);
   for(int j = N-1;j>=0;j--){

   		if(T[j]=='R'){
   		  	r.x = max(0,r.x-1);
		}	
		else if(T[j]=='D'){
   		  	u.x = max(0,u.x-1);
		}
		else if(T[j]=='L'){
   		  	r.y = min(W-1,r.y+1);
		}	
		else if(T[j]=='U'){
   		  	u.y = min(H-1,u.y+1);
		}
		if(S[j]=='R'){
			if(r.y==0) {
				cout<<"NO"<<endl;
				return;
			}
			r.y = r.y-1;
		}	
		else if(S[j]=='D'){
   		  	if(u.y==0) {
				cout<<"NO"<<endl;
				return;
			}
			u.y = u.y-1;
		}
		else if(S[j]=='L'){
   		  	if(r.x==W-1) {
				cout<<"NO"<<endl;
				return;
			}
			r.x = r.x+1;
		}	
		else if(S[j]=='U'){
   		  	if(u.x==H-1) {
				cout<<"NO"<<endl;
				return;
			}
			u.x = u.x+1;
		}	
   }
  // cout<<u.x<<" "<<u.y<<" "<<r.x<<" "<<r.y<<endl;
   if(r.x<= y-1 && r.y>=y-1 && u.x<=x-1 && u.y>=x-1) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   
}
int main(){
	solve();
	return 0;
}