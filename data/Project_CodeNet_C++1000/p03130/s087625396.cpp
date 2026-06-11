#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[6];
  int d[4]={0,0,0,0};
  for(int i=0;i<6;i++){
    cin >> a[i];
    d[a[i]-1]++;
  }
  if(d[0]<=2&&d[1]<=2&&d[2]<=2&&d[3]<=2)cout << "YES";
  else cout << "NO";
}