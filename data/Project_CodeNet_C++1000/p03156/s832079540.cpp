#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int cnt1=0,cnt2=0,cnt3=0;
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    if(m<=a)cnt1++;
    else if(a<m && m<=b)cnt2++;
    else if(b<m)cnt3++;
  }
  cout << min(cnt1,min(cnt2,cnt3)) << endl;
}
