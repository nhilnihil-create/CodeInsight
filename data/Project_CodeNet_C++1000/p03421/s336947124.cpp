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

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

int main() {
  ll N,A,B;cin >> N >> A >> B;
  if(A+B>N+1){
    cout << -1 << endl;
    return 0;
  }
  if(B==1){
    if(A!=N){
      cout << -1 << endl;
    }else{
      repeat(i,N){
        cout << i+1;
        cout << (i==N-1? "\n":" ");
      }
    }
    return 0;
  }
  if(B==N){
    if(A!=1){
      cout << -1 << endl;
    }else{
      repeat(i,N){
        cout << N-i;
        cout << (i==N-1? "\n":" ");
      }
    }
    return 0;
  }
  ll rest = N-B+1-A;
  ll hoge = (N-B)/B*(B-1);
  hoge += max(0ll,(N)%B-1);
  if(rest > hoge){
    cout << -1 << endl;
    return 0;
  }

  vll a;
  ll Q = rest/(B-1);
  ll idx = 0;
  repeat(q,Q){
    idx += B;
    repeat(b,B){
      a.push_back(idx-b);
    }
  }
  ll R = rest%(B-1)? rest%(B-1)+1:0;
  idx += R;
  repeat(b,R){
    a.push_back(idx-b);
  }
  repeat(b,N-B-idx){
    a.push_back(idx+b+1);
  }
  repeat(b,B){
    a.push_back(N-b);
  }
  repeat(i,N){
    cout << a[i];
    cout << (i==N-1? "\n":" ");
  }
  return 0;
}
