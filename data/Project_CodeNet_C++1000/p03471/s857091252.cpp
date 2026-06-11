#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,y,ans1=-1,ans2=-1,ans3=-1;
  cin >> n >> y;
  for(long i=0;i<=n&&i*10000<=y;i++) {
    for(long j=0;i+j<=n&&i*10000+j*5000<=y;j++) {
      if(i+j+(y-i*10000-j*5000)/1000==n) ans1=i,ans2=j,ans3=(y-i*10000-j*5000)/1000;
    }
  }
  cout << ans1 << " " << ans2 << " " << ans3 << endl;
}