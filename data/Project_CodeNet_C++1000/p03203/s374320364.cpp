#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int h,w,n;
int p[SIZE];
set<P> s;

int main(){
  cin >> h >> w >> n;
  rep(i,0,n){
    int x,y;
    cin >> x >> y;
    s.insert(P(x,y));
  }
  int k = h;
  int x=1,y=1;
  p[1] = 1;
  rep(i,0,h){
    if(s.find(P(x+1,y)) != s.end()){
      k = x;
      break;
    }else{
      x++;
    }
    if(s.find(P(x,y+1)) == s.end() && y<w){
      y++;
    }
    p[x] = y;
  }
  for(auto v : s){
    if(v.second <= p[v.first]){
      k = min(k,v.first-1);
    }
  }

  cout << k << endl;


  return 0;
}
