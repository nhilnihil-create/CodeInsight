#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  if(n==3){
    cout << 2 << " " << 5 << " " << 63 << endl;
    return 0;
  }
  if(n==4){
    cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
    return 0;
  }
  if(n==5){
    cout << 2 << " " << 5 << " " << 20 << " " << 50 << " " << 63 << endl;
    return 0;
  }
  vector<int> a(n);
  int cnt=0;
  int sum=0;
  for(int i=1;i<=30000;i++){
    if(i%2==0||i%3==0){
      a[cnt]=i;
      cnt++;
      sum+=i;
    }
    if(cnt==n){
      break;
    }
  }
  if(sum%6==2){
    a[4]=30000;
  }
  if(sum%6==3){
    a[5]=30000;
  }
  if(sum%6==5){
    a[5]=29998;
  }
  for(int i=0;i<n;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}