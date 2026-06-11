#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
  int a;
  string ans="AGC";
    cin >> a;
    if(a<1200)
      ans = "ABC";
    else if(a<2800)
      ans = "ARC";
    cout << ans << endl;
}