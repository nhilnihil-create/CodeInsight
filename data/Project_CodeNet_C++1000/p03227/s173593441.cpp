#include<bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  if (S.size()!=2) reverse(S.begin(), S.end());
  cout<<S<<endl;
}