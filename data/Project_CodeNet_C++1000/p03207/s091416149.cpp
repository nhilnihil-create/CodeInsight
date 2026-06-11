 #include <bits/stdc++.h>
using namespace std;

int main() {
int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i<n; ++i){
    cin >> p.at(i);
  }
  sort(p.begin(), p.end());
  p.at(n-1) /=2;
  int total = 0;
  for(int i= 0;i<n; ++i){
    total += p.at(i);
  }
  cout << total << endl;
}
