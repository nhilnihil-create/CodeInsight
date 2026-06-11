#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;


int main(){
  int n;
  cin >> n;
  vector<tuple<string,int,int>> a;
  rep(i,0,n){
    string s;
    cin >> s;
    int point;
    cin >> point;
    point *=-1;
    a.emplace_back(s,point,i+1);
  }
  sort(a.begin(),a.end());

  for(auto p:a) cout << get<2>(p) << endl;

}