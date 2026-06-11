#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  int cur[n];
  rep(i,0,n) cur[i]=0;
  int j=0;
  int cnt=0;
  while(j<n){
    if(cur[j]==a[j]) j++;
    else{
      int k=j;
      while(k<n && cur[k]<a[k]){
        cur[k]++;
        k++;
      }
      cnt++;
    }
  }
  cout<<cnt<<endl;
}