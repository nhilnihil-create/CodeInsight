#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,q,c=0;
  string s;
  cin >> n >> q >> s;
  vector<int>a(n,0);
  for(int i=1;i<n;i++){
    if(s.at(i-1)=='A'&&s.at(i)=='C')
      c++;
    a.at(i)=c;
  }
  int bb,b;
  for(int i=0;i<q;i++){
    cin >> bb >> b;
    cout << a.at(b-1)-a.at(bb-1) << endl;
  }
  return 0;
}