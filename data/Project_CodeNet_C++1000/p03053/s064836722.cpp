#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w,ans=0,b=0;
  cin >> h >> w;
  vector<string> a(h);
  vector<vector<bool>> is_black(h,vector<bool>(w,false));
  queue<vector<long>> q;
  for(long i=0;i<h;i++) cin >> a[i];

  for(long i=0;i<h;i++) {
    for(long j=0;j<w;j++) {
      if(a[i][j]=='#') {
        b++;
        is_black[i][j]=true;
        q.push({i,j});
      }
    }
  }
  while(b<h*w) {
    ans++;
    long x=q.size();
    for(long c=0;c<x;c++) {
      long i=q.front()[0],j=q.front()[1];
      if(i!=0) {
        if(!(is_black[i-1][j])) {
          b++;
          is_black[i-1][j]=true;
          q.push({i-1,j});
        }
      }
      if(i+1!=h) {
        if(!(is_black[i+1][j])) {
          b++;
          is_black[i+1][j]=true;
          q.push({i+1,j});
        }
      }
      if(j!=0) {
        if(!(is_black[i][j-1])) {
          b++;
          is_black[i][j-1]=true;
          q.push({i,j-1});
        }
      }
      if(j+1!=w) {
        if(!(is_black[i][j+1])) {
          b++;
          is_black[i][j+1]=true;
          q.push({i,j+1});
        }
      }
      q.pop();
    }
  }
  cout << ans << endl;
}