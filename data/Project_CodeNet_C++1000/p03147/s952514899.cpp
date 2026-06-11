#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,s;
  cin >> n;
  vector<int> h(n+1);
  h.at(0)=0;
  for(i=1;i<=n;i++){
    cin >> h.at(i);
  }
  
  s=0;
  for(i=1;i<=n;i++){
    s += max(h.at(i)-h.at(i-1),0);
  }
  
  cout << s << endl;
}