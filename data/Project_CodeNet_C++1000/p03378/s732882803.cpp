#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x,a[100];
  cin>>n>>m>>x;
  for(int i=1;i<=m;i++){
    cin>>a[i];
  }
  int left=0;
  for(int i=1;i<=m;i++){
    if(a[i]>=1&&a[i]<=x){
      left++;
    }
  }
  int right=0;
  for(int i=1;i<=m;i++){
    if(a[i]>=x&&a[i]<=n+1){
      right++;
    }
  }
  cout<<min(right,left)<<endl;
}
