#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<tuple<string, int, int>> R;
  for (int i = 0; i < N; i++){
    string s;
    int p;
    cin >> s >> p;
    R.push_back(make_tuple(s,100-p,i+1));
  }
  
  sort(R.begin(), R.end());
  
  for (tuple<string, int, int> r : R){
	string s; 
    int p;
    int n;
    tie(s, p, n) = r;
    cout << n << endl;
  }
}