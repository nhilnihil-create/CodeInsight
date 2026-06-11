#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <random>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[200020];

int main(){
  int n;
  cin >> n;
  if(n%2){
    cout << (n-1)*(n-1)/2 << endl;
    rep(i,n){
      rep(j,n){
        if(i<j){
          if(i+j+2!=n){
            cout << i+1 << ' ' << j+1 << endl;
            v[i].push_back(j);
            v[j].push_back(i);
          }
        }
      }
    }
  }else{
    cout << (n-2)*n/2 << endl;
    rep(i,n){
      rep(j,n){
        if(i<j){
          if(i+j+2!=n+1)cout << i+1 << ' ' << j+1 << endl;
        }
      }
    }
  }
return 0;}