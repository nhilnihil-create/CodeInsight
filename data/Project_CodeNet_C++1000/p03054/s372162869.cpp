#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,n,a,b,r1=0,r2=0,c1=0,c2=0,ans=0;
  cin >> h >> w >> n >> a >> b;
  string s1,s2;
  cin >> s1 >> s2;
  for (int i=n-1;i>-1;i--){
    if (i!=n-1){
      if (s2.at(i)=='L' && r1!=0) r1--;
      if (s2.at(i)=='R' && r2!=0) r2--;
      if (s2.at(i)=='U' && c1!=0) c1--;
      if (s2.at(i)=='D' && c2!=0) c2--;
    }

    if (s1.at(i)=='R') r1++;
    if (s1.at(i)=='L') r2++;
    if (s1.at(i)=='D') c1++;
    if (s1.at(i)=='U') c2++;
    if (r1+r2>=w) {ans=1;break;}
    if (c1+c2>=h) {ans=1;break;}
  }
  if (ans==1) {cout << "NO" << endl;return 0;}
  if (b>r2 && b<w+1-r1 && a>c2 && a<h+1-c1) cout << "YES" << endl;
  else cout << "NO" << endl;
}
