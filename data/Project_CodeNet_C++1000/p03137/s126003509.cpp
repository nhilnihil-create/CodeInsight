#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,m,i,s;
  cin >> n >> m;
  if(n>=m){
    cout << 0 << endl;
    return 0;
  }
  vector<int> x(m);
  for(i=0;i<m;i++){
    cin >> x.at(i);
  }
  sort(x.begin(),x.end());
  
  vector<int> d(m-1);
  for(i=0;i<m-1;i++){
    d.at(i)=x.at(i+1)-x.at(i);
  }
  sort(d.begin(),d.end());
  
  s=0;
  for(i=0;i<m-n;i++){
    s += d.at(i);
  }
  cout << s << endl;
}