#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
//string S[N];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  string s[N];
  rep(i,N) cin >> s[i];
  int x=0;
  int y=0;
  ll ans=0;
  int flag=0;
  rep(x,N){
  rep(i,N){
    rep(j,N){
      if(s[(x+i)%N][(y+j)%N] == s[(x+j)%N][(y+i)%N]){
	if(i==N-1 && j==N-1){
	  ans++;
	}	
      }
      else{
	flag=1;
	break;
      }
    }
    if(flag==1){
      flag=0;
      break;
    }
  }
  }
  /*  x = y =0;
  flag=0;
  rep(y,N){
  rep(i,N){
    rep(j,N){
      if(s[(x+i)%N][(y+j)%N] == s[(x+j)%N][(x+i)%N]){
	if(i==N-1 && j==N-1){
          ans++;
	}	
      }
      else{
	flag=1;
        break;
      }
    }
    if(flag==1){
      flag=0;
      break;
    }
  }
  }
  */
  cout << ans * (N*1LL) << endl;
  return 0;
    

}
