#include <bits/stdc++.h>
using namespace std;
int main(){
  int a[4]={},cnt1=0,cnt2=0;
  for(int i=0;i<6;i++){
    int b;
    cin >> b;
    a[b-1]++;
  }
  for(int i=0;i<6;i++){
    if(a[i]==1) cnt1++;
    if(a[i]==2) cnt2++;
  }
  if(cnt1==2&&cnt2==2) cout << "YES" << endl;
  else cout << "NO" << endl;
}