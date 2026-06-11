#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
int n;
int loop(int m){
  int res;
  m*=2;
  rep1(i,m){
    if(m%i==0){
      if(m/i-1==i){
	res=i;
	return res;
      }
    }
  }
  return -1;
}
void solve(){
  int m=loop(n);
  if(m==-1){
    prin("No");
    return ;
  }
  else{
    prin("Yes");
    prin(m+1);
    int res[600][600];
    int i=0,j=0,l=0,p=1;
    while(i<m){
      rep(k,m-l){
	res[i][k+j]=k+p;
	res[k+i+1][j]=k+p;
      }
      p=1+res[i][m-1];
      i++;j++;l++;
    }
    rep(a,m+1){
      cout<<m<<" ";
      rep(b,m){
	cout<<res[a][b]<<" ";
      }
      cout<<"\n";
    }
    return ;
    }
  
}
int main(){
  cin>>n;
  solve();

  return 0;
}
