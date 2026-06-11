#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  int cnt = 0, cnt1 = 0;
  for(int i=0; i<n; ++i){
    int res = 1;
    while(res<=d){
      if(res==0) break;
      if(res>0){
        ++cnt;
        res += a[i];
      }
    }
    cnt1 += cnt;
    cnt = 0;
  }

  cout << cnt1 + x << endl;

  return 0;
}