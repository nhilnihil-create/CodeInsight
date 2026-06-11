#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int>sum(n+1);
  for(int i=0;i<n-1;i++){
    if(s.at(i)=='A'&&s.at(i+1)=='C'){
      sum.at(i+2)+=sum.at(i+1)+1;
    }
    else{
      sum.at(i+2)+=sum.at(i+1);
    }
  }
  for(int i=0;i<q;i++){
    int l,r;
    cin >> l >> r;
    cout << (sum.at(r)-sum.at(l)) << endl;
  }
}