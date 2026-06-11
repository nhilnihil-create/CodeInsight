#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  int n; cin >> n;
  vector<int> t(n+1,0);
  vector<P> xy(n+1,make_pair(0,0));
  rep2(i,n){
    int a,b;
    cin >> t[i] >> a >> b;
    xy[i] = make_pair(a,b);
  }
  bool flg = true;
  rep2(i,n){
    int t1 = t[i] - t[i-1];
    int x1 = abs(xy[i].first - xy[i-1].first);
    int y1 = abs(xy[i].second - xy[i-1].second);
    if(t1 < x1+y1) flg = false;
    if((t1-x1-y1)%2!=0) flg = false;    
  }
  
  puts(flg?"Yes":"No");
  return 0;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/
