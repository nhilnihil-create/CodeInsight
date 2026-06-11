#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,x;
  cin>>n>>x;
  int sum=0;
  int mi=1000;
  rep(i,0,n){
    int a;
    cin>>a;
    sum+=a;
    mi=min(mi,a);
  }
  cout<<n+(x-sum)/mi<<endl;
}