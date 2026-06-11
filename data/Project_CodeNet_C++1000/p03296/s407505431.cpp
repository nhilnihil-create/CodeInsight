#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  cin >> a[0];
  int l=1,c=0;
  for(int i=1;i<n;i++){
    cin >> a[i];
    if(a[i]==a[i-1]){
      l++;
    }
    else{
      c+=l/2;
      l=1;
    }
  }
  c+=l/2;
  cout << c;
}