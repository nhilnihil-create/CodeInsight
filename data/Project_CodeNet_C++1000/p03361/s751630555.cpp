#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> vec;
  rep(i, h){
    string str;
    cin >> str;
    vec.push_back(str);
  }
  rep(i, h){
    rep(j, w){
      if(vec[i][j] == '.') continue;
      else{
        bool found = false;
      	for (int x = -1, y = 0, k = 0; k < 4; x += y, y = x - y, x = y - x, ++k) {
   		  if((0 <= i+y) && (i+y < h) && (0 <= j+x) && (j+x < w)){
            if(vec[i+y][j+x] == '#'){
              found = true;
            }
          }
  		}
        if(!found){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
