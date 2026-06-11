#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int mini=1e8;
  for(int i=0;i<n;i++){
      int a;
      cin>>a;
      int cnt=0;
      while(a%2==0){
          cnt++;
          a/=2;
      }
      mini=min(mini,cnt);
    }
    cout<<mini<<endl;
}