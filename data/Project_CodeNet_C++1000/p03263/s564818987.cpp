#include <bits/stdc++.h>
#define P pair<int, int>
#define PP pair<P, P>

using namespace std;

int main(){
  int h, w, a[509][509];
  cin >>h >> w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++)cin >> a[i][j];
  }
  queue<PP> q;
  for(int i=1;i<=h-1;i++){
    for(int j=1;j<=w;j++){
      if(a[i][j]%2==1){
        a[i][j]--;
        a[i+1][j]++;
        q.push(PP(P(i, j), P(i+1, j)));
      }
    }
  }
  for(int j=1;j<w;j++){
    if(a[h][j]%2==1){
      a[h][j]--;
      a[h][j+1]++;
      q.push(PP(P(h, j), P(h, j+1)));
    }
  }
  cout << q.size() << endl;
  while(!q.empty()){
    PP pp = q.front();q.pop();
    cout << pp.first.first << ' ' << pp.first.second << ' ';
    cout << pp.second.first << ' ' << pp.second.second << '\n';
  }
}

