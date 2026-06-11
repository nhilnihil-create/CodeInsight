#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e18+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll A,B;
char grid[105][105];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>A>>B;

ll a=0,b=0;
rep(h,100){
	ll hh=99-h;
	if(hh%2==1){
		rep(w,100){
		if(w%2==0&&b<B-1){
			grid[hh][w]='#'; b++;
		}else{
			grid[hh][w]='.';
		}
		}
	}else{
		rep(w,100) grid[hh][w]='.';
		if(b==B-1) break;
	}
}
rep(h,100){
	if(grid[h][0]=='.') break;
	if(h%2==0){
		rep(w,100){
		if(w%2==0&&a<A-1){
			grid[h][w]='.'; a++;
		}else{
			grid[h][w]='#';
		}
		}
	}else{
		rep(w,100) grid[h][w]='#';
	}
}

cout<<100<<" "<<100<<endl;
rep(h,100){
	rep(w,100){
		cout<<grid[h][w];
	}
	cout<<endl;
}

}
	
