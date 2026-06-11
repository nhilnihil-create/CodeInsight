#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  char s;
  for(int i=0; i<n; cin>>s,i++) if(s=='Y'){
    cout<<"Four"; return 0;
  } 
  cout<<"Three";
}