#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

int main(){
  int N;cin>>N;
  bool isok=true;
  vll U(N),V(N);
  repeat(i,N){
    ll X,Y;
    cin >> X >> Y;
    U[i] = (X+Y);
    V[i] = (X-Y);
    isok &= abs(U[0]+U[i])%2==0;
  }
  if(!isok){
    cout << -1 << endl;
    return 0;
  }
  int m = (abs(U[0])&1? 31:32);
  cout <<m<< endl;
  repeat(i,m){
    if(i==31)cout << 1 << endl;
    else{
      cout << (1<<i) << (i+1<m? " ":"\n");
    }
  }
  repeat(i,N){
    ll UU = (U[i]+(1<<31)-1-!(abs(U[i])&1))/2;
    ll VV = (V[i]+(1<<31)-1-!(abs(V[i])&1))/2;
    string w(m,'R');
    repeat(j,31){
      bool ud = (UU>>j)&1;
      bool vd = (VV>>j)&1;
      if(ud){
        if(vd){
          w[j] = 'R';
        }else{
          w[j] = 'U';
        }
      }else{
        if(vd){
          w[j] = 'D';
        }else{
          w[j] = 'L';
        }
      }
    }
    cout << w << endl;
  }
  return 0;
}
