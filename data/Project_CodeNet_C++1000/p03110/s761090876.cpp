#include<bits/stdc++.h>
using namespace std;
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
int main(){
  int n;
  cin >> n;
  double ans=0;
  for(int i=0;i<n;i++){
    double a;
    string s;
    cin >> a >> s;
    if(s=="JPY")  ans+=a;
    else ans+=380000.0*a;
  }
  output(ans,10);
  return 0;
}