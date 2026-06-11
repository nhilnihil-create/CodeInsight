#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<long long> x(5);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(s[0]=='M') x[0]++;
    else if(s[0]=='A') x[1]++;
    else if(s[0]=='R') x[2]++;
    else if(s[0]=='C') x[3]++;
    else if(s[0]=='H') x[4]++;
  }
  long long ans=0;
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int l=j+1;l<5;l++){
        ans+=x[i]*x[j]*x[l];
      }
    }
  }
  cout << ans << endl;
}