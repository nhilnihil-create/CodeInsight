#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int N, H, W; cin >> N >> H >> W;
  int a, b;
  int ans = 0;
  rep(i,N){
    cin >> a >> b;
    if(a>=H && b>=W) ans++;
  }
  cout << ans << endl;
  return 0;
}
