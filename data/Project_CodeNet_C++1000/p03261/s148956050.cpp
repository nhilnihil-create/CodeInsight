#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,n) {
    cin>>s[i];
  }
  bool ans = true;
  for(int i=1; i<n; i++) {
    int m = s.at(i-1).size();
    if(s.at(i).at(0)!=s.at(i-1).at(m-1)) {
      cout<<"No"<<endl;
      return 0;
    }
  }
  sort(s.begin(), s.end());
  for(int i=1; i<n; i++) {
    if(s.at(i) == s.at(i-1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
