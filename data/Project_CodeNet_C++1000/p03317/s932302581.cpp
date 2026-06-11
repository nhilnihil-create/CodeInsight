#include<bits/stdc++.h>
using namespace std;
int size(int n,int k){
  int ans=1,s=k;
  while(s<n){
    ans++;
    s+=k-1;
  }
  return ans;
}
int main(){
  int n,k;
  cin >> n >> k;
  int ans=1,tmp;
  for(int i=0;i<n;i++){
    cin >> tmp;
    if(tmp==1){
      tmp=i;
      break;
    }
  }

  if(tmp+k-1>n-1 || tmp-k+1<0){
    cout << size(n,k) << endl;
  }else{
    cout << size(tmp,k)+size(n-tmp+1,k)<< endl;
  }
  return 0;
}