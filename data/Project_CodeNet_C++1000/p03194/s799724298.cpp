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
  ll N, P; cin >> N >> P;
  vector<ll> so;
  for(ll i=1; i*i<=P; i++){
    if(P%i==0) {
      so.pb(i);
      if(P/i!=i) so.pb(P/i);
    }
  }
  sort(all(so));
  reverse(all(so));
  rep(i,(int)so.size()){
    //cout << so[i] << endl;
  }
  rep(i,(int)so.size()){
    if(so[i]==1) { cout << 1 << endl; return 0;}
    ll P_ = P;
    ll counter = 0;
    while(1){
      if(P_%so[i]==0){
        counter++;
        P_ /= so[i];
      }
      else{
        if(counter >= N){
          cout << so[i] << endl;
          return 0;
        }
        break;
      }
    }
  }
  return 0;
}
