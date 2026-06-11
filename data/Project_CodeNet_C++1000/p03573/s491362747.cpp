#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a[3];
    for(int i=0; i<3; i++) cin >> a[i];
    sort(a,  a+3);
  int ans = a[0];
    if(a[0]==a[1]) ans = a[2];
  cout << ans << endl;

}