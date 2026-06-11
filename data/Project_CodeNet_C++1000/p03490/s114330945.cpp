#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

bool check(int x, vector<int> ds) {
  sort(ds.begin(),ds.end());
  reverse(ds.begin(),ds.end());
  int a=0;
  for(auto& d : ds) {
    if(abs(a+d-x)<abs(a-d-x)) {
      a+=d;
    } else {
      a-=d;
    }
  }
  if(a==x)
    return true;
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  string s;
  int x,y;
  cin>>s>>x>>y;
  vector<int> d;
  int a=0;
  for(auto& ch : s) {
    if(ch=='T') {
      d.push_back(a);
      a=0;
    } else {
      a++;
    }
  }
  d.push_back(a);
  vector<int> d1;
  vector<int> d2;
  rep(i,d.size()) {
    if(i==0) x-=d[i];
    else if(i%2==0) d1.push_back(d[i]);
    else d2.push_back(d[i]);
  }
  if(check(x,d1)&&check(y,d2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
