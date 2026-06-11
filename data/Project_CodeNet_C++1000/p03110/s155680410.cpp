#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  double ans=0;
  rep(i,n){
    double a;
    string s;
    cin >> a >> s;
    if(s[0]=='J')ans+=a;
    else ans+=a*380000;
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
