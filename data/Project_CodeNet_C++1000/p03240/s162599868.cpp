#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

typedef struct{
  int x, y, h;
} point;

int main(){
  int n;
  cin >> n;
  vector<point> vec(n);
  rep(i, n){
    point p;
    cin >> p.x >> p.y >> p.h;
    vec[i] = p;
  }
  for(int i=0; i<=100; i++){
    for(int j=0; j<=100; j++){
      int H;
      rep(k, n){
        if(vec[k].h != 0){
          H = vec[k].h+abs(vec[k].x-j)+abs(vec[k].y-i);
          break;
        }
      }
      bool isok = true;
      rep(k, n){
        if(vec[k].h != 0){
          if(H != vec[k].h+abs(vec[k].x-j)+abs(vec[k].y-i)){
            isok = false;
            break;
          }
        }
      }
      if(!isok) continue;
      rep(k, n){
        if(vec[k].h != max(H-abs(vec[k].x-j)-abs(vec[k].y-i), 0)){
          isok = false;
          break;
        }
      }
      if(!isok) continue;
      cout << j << " " << i << " " << H << endl;
      return 0;
    } 
  }
  return 0;
}


