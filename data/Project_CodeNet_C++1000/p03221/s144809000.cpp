#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,m; cin>>n>>m;
  vector<int> p(m),y(m);
  map<int,int> t;
  for(int i=0; i<m; i++){
    cin >> p.at(i) >> y.at(i);
    p.at(i)--;
    t[y.at(i)] = i;
  }
  sort(y.begin(),y.end());
  vector<int> num(n), ans(m);
  for(int i=0; i<m; i++){
    int b = t[y.at(i)];
    num.at(p.at(b))++;
    ans.at(b) = num.at(p.at(b));
  }
  for(int i=0; i<m; i++){
    string x = to_string(p.at(i)+1);
    string y = to_string(ans.at(i));
    cout << string(6-x.size(),'0')<<x;
    cout << string(6-y.size(),'0')<<y;
    cout << endl;
  }
  
  
  
}