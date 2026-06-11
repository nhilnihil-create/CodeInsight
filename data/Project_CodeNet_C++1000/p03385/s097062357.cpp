#include <bits/stdc++.h>
using namespace std;

int main() {
int A,B,C;
string S;
cin>>S;

  if(S=="abc" || S=="acb" || S=="bac" || S=="bca" || S=="cab" || S=="cba") S="Yes";
  else S="No";
  cout<<S;
}