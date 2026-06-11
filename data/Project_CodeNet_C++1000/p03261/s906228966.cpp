#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n;
  cin>>n;
  vector<string>a(n);
  set<string>memo;
  string s="Yes";
  char c;
  cin>>a[0];
  memo.insert(a[0]);
  c=a[0].at(a[0].size()-1);
  rep2(i,1,n) {
    cin>>a[i];
    if(memo.count(a[i])){
      s="No";
    }
    memo.insert(a[i]);
    if(c!=a[i].at(0)){
      s="No";
    }
    c=a[i].at(a[i].size()-1);
  }
  cout<<s<<endl;
}