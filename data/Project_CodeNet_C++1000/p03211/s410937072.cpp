#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int n = 753;
  int ans = 9999;
  int sa=0;
  for(int i=0; i<S.size()-2; i++){
    char iti = S.at(i); char ni= S.at(i+1); char san= S.at(i+2);
    string s3;
    s3 += iti;
    s3 += ni;
    s3 += san;
    int X = stoi(s3);
    if(X>n)sa=X-n;
    else sa=n-X;
    if(sa<ans)ans=sa;
  }
  cout << ans << endl;
  
}