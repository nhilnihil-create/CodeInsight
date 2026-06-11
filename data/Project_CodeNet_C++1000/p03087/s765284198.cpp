#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  string s;
  scanf("%d %d", &n, &q);
  cin >> s;
  vector<int> a(n + 1, 0);
  for(int i = 0; i < n - 1; i++){
    if(s[i] == 'A' && s[i + 1] == 'C') a[i + 1] = a[i] + 1;
    else a[i + 1] = a[i];
  }
  for(int i = 0; i < q; i++){
    int b, e;
    scanf("%d %d", &b, &e);
    b--; e--;
    cout << a[e] - a[b] << endl;
  }
}