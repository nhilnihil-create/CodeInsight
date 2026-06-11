#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  double x[n],s=0;
  string t[n];
  for(int i=0;i<n;i++){
    cin >> x[i] >> t[i];
    if(t[i]=="JPY")s+=x[i];
    else s+=x[i]*380000;
  }
  cout << fixed << setprecision(15) << s;
}
