#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n);
  vector<int> y(m);
  for (int i=0 ; i<n ; i++)
    cin >> x.at(i);
  for (int i=0 ; i<m ; i++)
    cin >> y.at(i);
  
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  if (max(x.at(n-1), X) < min(y.at(0), Y))
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}