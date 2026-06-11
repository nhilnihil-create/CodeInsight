#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int ans=pow(3,n),a[n];
  int f=1;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]%2==0){
      f*=2;
    }
  }
  cout << ans-f << endl;
}
