#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9+7;
typedef pair<int,int> P;

int main() {
  string s; cin>>s;
  int w=0;
  for(int i=0;i<s.size();i++) w+=s[i]=='x';
  if (w>7) cout<<"NO"<<endl; else cout<<"YES"<<endl;
}