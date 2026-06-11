#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

int table[110][110];

int main(){
  ll a,b;cin>>a>>b;
  cout<<100<<" "<<100<<endl;
  rep(i,100){
  	rep(j,100){
  		if(i<50){
  			table[i][j]=1;
  		}
  	}
  }
  a--;
  b--;
  rep(i,50){
  	if(i%2==0){
	  	rep(j,100){
	  		if(a==0){
	  			break;
	  		}
	  		if(j%2==0){
	  			table[i][j]=0;
	  			a--;
	  		}
	  	}
	  }
  }
  FOR(i,50,100){
  	if(i%2==1){
	  	rep(j,100){
	  		if(b==0){
	  			break;
	  		}
	  		if(j%2==0){
	  			table[i][j]=1;
	  			b--;
	  		}
	  	}
	  }
  }

	rep(i,100){
  	rep(j,100){
  		if(table[i][j]==0){
  			cout<<".";
  		}else{
  			cout<<"#";
  		}
  	}
  	cout<<endl;
  }  

  return 0;
}