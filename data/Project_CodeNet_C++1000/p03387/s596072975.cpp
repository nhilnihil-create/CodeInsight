#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main() {
  vector<int> a(3);
  rep(i,3) cin >> a[i];
  sort(a.begin(),a.end());
  int da=a[2]-a[0]; int db=a[2]-a[1];

  int cnt=0; cnt+=db/2;
  if(db%2==1){
    cnt++; da--;
  }

  if(da%2==0)cnt+=da/2;
  else{
    cnt+=da/2+2;
  }

  cout << cnt << endl;
}
