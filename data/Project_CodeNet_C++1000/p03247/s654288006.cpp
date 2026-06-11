#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 1e9+7;
int main(void){
  int n;
  vector< P > points;
  set< int > xs;
  set< int > ys;
  cin >> n;
  for(int i = 0;i < n;++i){
    int x,y;
    cin >> x >> y;
    points.push_back(P(x,y));
  }
    
  for(int i = 1;i < n;++i){
    int x1 = (int)abs(points[0].first);
    int y1 = (int)abs(points[0].second);
    int x2 = (int)abs(points[i].first);
    int y2 = (int)abs(points[i].second);
    if((x1 + y1) % 2 != (x2 + y2) % 2){
      puts("-1");
      return 0;
    }
  }

  if((points[0].first + points[0].second) % 2 == 0){
    cout << 32 << endl;
    cout << "1 ";
  }else{
    cout << 31 << endl;
  }
  cout << "1";
  for(int i = 1;i < 31;++i){
    cout << " " << (1 << i);
  }
  cout << endl;
  for(P point : points){
    int x,y;
    tie(x,y) = point;
    if((x+y) % 2 == 0){
      cout << "R";
      --x;
    }
    int bitu = (x + y + (1 << 31) - 1) / 2;
    int bitv = (x - y + (1 << 31) - 1) / 2;
    int resx = 0,resy = 0;
    for(int i = 0;i < 31;++i){
      if(bitu & (1 << i)){
        if(bitv & (1 << i)){
          cout << "R";
          resx += (1 << i);
        }else{
          cout << "U";
          resy += (1 << i);
        }
      }else{
        if(bitv & (1 << i)){
          cout << "D";
          resy -= (1 << i);
        }else{
          cout << "L";
          resx -= (1 << i);
        }
      }
    }
    cout << endl;
    //cout << resx << " " << resy << endl;
  }
  return 0;
}

