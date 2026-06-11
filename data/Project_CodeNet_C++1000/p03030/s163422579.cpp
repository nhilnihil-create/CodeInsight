#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<pair<string,int>,int>> sp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int p; cin >> p;
    sp.push_back(pair<pair<string,int>,int>(pair<string,int>(s,-1*p),i+1));
  }
  sort(sp.begin(),sp.end());
  for (auto && a : sp) {
    cout << a.second << endl;
  }
}