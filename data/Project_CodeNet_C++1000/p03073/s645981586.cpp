#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  string s;
  cin >>s;
  int n=s.size();
  int zero=0;
  int ichi=0;
  for(int i=0;i<n;i++){
    if(i%2==0&&s[i]!='1')zero++;
    if(i%2==1&&s[i]!='0')zero++;
    if(i%2==0&&s[i]!='0')ichi++;
    if(i%2==1&&s[i]!='1')ichi++;
  }
  int kotae=min(zero,ichi);
  cout<<kotae<<endl;
  return 0;
}