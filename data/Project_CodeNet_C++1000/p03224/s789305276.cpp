#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  int n,k=0;
  vector<int> v[1000];
  cin>>n;
  fr(i,1000){
    if((i*(i-1))/2==n){
      k=i;
      break;
    }
  }
  if(k==0){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl<<k<<endl;
  Fr(i,k-1){
    ifr(j,i) v[k-i].pb(n-j-(i*(i-1))/2);
  }
  fr(i,k){
    cout<<k-1<<" ";
    Fr(j,i) cout<<v[j][i-j]<<" ";
    fr(j,v[i+1].size()) cout<<v[i+1][j]<<" ";
    cout<<endl;
  }
}