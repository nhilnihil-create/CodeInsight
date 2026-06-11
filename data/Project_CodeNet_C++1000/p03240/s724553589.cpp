#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;
ll mod = 1e9+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int main(){
  int N;
  cin >> N;
  vector<int> X(N), Y(N), H(N);
  rep(i, N) cin >> X[i] >> Y[i] >> H[i];

  for(int x=0; x<=100; x++){
    for(int y=0; y<=100; y++){
      bool ok = true;
      int h_candidate = -1;
      // H[i] > 0
      rep(i, N){
        if(H[i] > 0){
          int tmp_h = abs(x-X[i]) + abs(y-Y[i]) + H[i];
          if(h_candidate == -1){
            h_candidate = tmp_h;
          }else{
            if(h_candidate != tmp_h){
              ok = false;
              break;
            }
          }
        }
      }

      if(!ok) continue;

      // H[i] == 0
      rep(i, N){
        if(H[i] == 0){
          int judge = h_candidate - (abs(x-X[i]) + abs(y-Y[i]));
          if(judge > 0){
            ok = false;
            break;
          }
        }
      }

      if(ok){
        cout << x << " " << y << " " << h_candidate << endl;
        return 0;
      }
    }
  }


  return 0;
}
