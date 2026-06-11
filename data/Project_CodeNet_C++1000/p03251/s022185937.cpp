#include<bits/stdc++.h>

#define llint long long int
#define pb push_back

using namespace std;

int main(){
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int xs[n], ys[m];
  for(int i = 0; i < n; i++)
    cin >> xs[i];
  for(int i = 0; i < m; i++)
    cin >> ys[i];
  sort(xs, xs+n);
  sort(ys, ys+m);
  int l = max(x, xs[n-1]);
  int r = min(y, ys[0]);
  if(r > l)
    cout << "No War";
  else
    cout << "War";
  return 0;
}