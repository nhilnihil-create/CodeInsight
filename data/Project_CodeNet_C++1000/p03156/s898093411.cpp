#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, A, B, a[N];
int cnta, cntb, cntc;
int main(){
    cin >> n >> A >> B;
  	for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] <= A) cnta++;
      else if (a[i] <= B) cntb++;
      else cntc++;
    }
  cout << min(cnta, min(cntb, cntc)) << endl;
  return 0;
}