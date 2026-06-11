#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string s, t; cin >> s >> t;
  int n = s.size();
  map<char,char> a,b;
  bool check = true;
  rep(i,n){
    if (a.count(s[i]) && a[s[i]]!=t[i]) check = false;
    else if (b.count(t[i]) && b[t[i]]!=s[i]) check = false;

    a[s[i]] = t[i];
    b[t[i]] = s[i];
  }
  cout << (check ? "Yes" : "No") << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
