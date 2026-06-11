#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  double a[n],b=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    b+=a[i];
  }
  b/=n;
  double c=99999999;
  for(int i=0;i<n;i++){
    if(c>abs(b-a[i]))c=abs(b-a[i]);
  }
  for(int i=0;i<n;i++){
    if(abs(b-a[i])==c){
      cout << i;
      return 0;
    }
  }
}
