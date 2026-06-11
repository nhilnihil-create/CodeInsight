#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  int n;
  cin >> n;
  vector<long> a(n);
  vector<bool> select(n,false);
  rep(i,n) cin >> a.at(i);
  sort(a.begin(),a.end());
  vector<long> two(33);
  two.at(0) = 1;
  rep(i,32) two.at(i+1) = two.at(i)*2;
  long ans = 0;
  for(int i=n-1;i>=1;i--){
    
    if(select.at(i)){
      a.pop_back();
      continue;
    }
    //rep(i,n) cout << select.at(i) << " ";
    //cout << endl;
    //rep(i,a.size()) cout << a.at(i) << "  :::";
    //cout << endl;
    long x = a.at(i);
    long sum = *upper_bound(two.begin(),two.end(),x);
    long y = sum - x;
    //a.pop_back();
    /*if(a.at(i-1) < y){
      a.pop_back();
      continue;
    }*/
    long id = lower_bound(a.begin(),a.end(),y) - a.begin();
    //cout << i << " " << id << endl;
    if(id == i){
      a.pop_back();
      continue;
    }
    //cout << y << ":y" << "  ";
    //rep(j,7) cout << select.at(id) << " ";
    if(a.at(id) == y && !select.at(id)){
      long ch = upper_bound(a.begin(),a.end(),y) - a.begin();
      //cout << ch << ":ch" << endl;
      int j;
      if(i == ch-1) j = ch-2;
      else j = ch-1;
      for(;j>=id;j--){
        if(select.at(j)) continue;
        select.at(j) = true;
        ans++;
        break;
      }
    }
    //rep(j,7) cout << select.at(id) << " ";
    //cout << endl;
    a.pop_back();
  }
  cout << ans << endl;
}
