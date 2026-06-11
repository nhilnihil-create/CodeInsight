#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n],b=0,g;
  for(int i=0;i<n;i++){
    cin >> a[i];
    g=0;
    while(a[i]%2==0){
      a[i]/=2;
      g++;
    }
    b+=g;
  }
  cout << b;
}
