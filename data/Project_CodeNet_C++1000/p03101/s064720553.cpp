#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)

//library----------------------------------------------


int main(){
  int H,W,h,w; cin>>H>>W>>h>>w;
  int ans = (H-h)*(W-w);
  printf("%d\n",ans);
  return 0;
}