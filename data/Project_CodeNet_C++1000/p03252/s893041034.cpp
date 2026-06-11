#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  string s, t;
  cin >> s >> t;
  int n = s.size();

  vector<vector<int>> a(26, vector<int>(0));
  set<vector<int>> h;

  for (int i = 0; i < n; i++){
    a[s[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++){
    h.insert(a[i]);
  }


  vector<vector<int>> b(26, vector<int>(0));
  set<vector<int>> g;
  
  for (int i = 0; i < n; i++){
    b[t[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < 26; i++){
    g.insert(b[i]);
  }
  if (h == g){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
    
  

  return 0;
}

