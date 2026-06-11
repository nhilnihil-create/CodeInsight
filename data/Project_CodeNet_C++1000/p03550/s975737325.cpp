#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,x,y,p,l;
  cin >> n >> x >> y;
  if(n == 1){
    long a;
    cin >> a;
    cout << abs(y-a) << endl;
    return 0;
  }
  for(int i = 0;i < n;i++){
    int a;
    cin >> a;
    if(i == n-2) p = a;
    if(i == n-1) l = a;
  }
  cout << max(abs(y-l),abs(p-l)) << endl;
}
