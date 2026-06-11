#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() { 
  int n, T;
  cin >> n >> T;
  vector<int> v;
  while(n--){
  	int c, t;
    cin >> c >> t;
    if(t <= T){
    	v.push_back(c);	
    }
  }
  if(v.size() != 0){
  	cout << *min_element(v.begin(), v.end()) << endl;
  }else{
  	cout << "TLE" << endl;
  }
  return 0; 
}