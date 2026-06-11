#include <iostream>
#include <cstdio>
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
#include <iomanip>
#include <cassert>
#include <float.h>
#include <random>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
#define debugArrayP(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge].first<< " " << x[hoge].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const int INF = INT_MAX;
const ll MOD = 1e9+7;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,Q;cin>>N>>Q;
  string s;cin>>s;
  s = "?"+s+"?";
  string t(Q,' '),d(Q,' ');
  repeat(i,Q){
    cin>>t[i]>>d[i];
  }
  int ans=N;
  int low=0,high=N+1;
  while(high-low>1){
    int mid=(high+low)/2;
    int cur=mid;
    bool exist=true;
    repeat(i,Q){
      if(s[cur]==t[i]){
        cur += 2*(d[i]=='R')-1;
        if(cur==0){
          exist=false;
          break;
        }
      }
    }
    if(exist){
      high=mid;
    }else{
      low=mid;
    }
  }
  ans -= low;
  low=0,high=N+1;
  while(high-low>1){
    int mid=(high+low)/2;
    int cur=mid;
    bool exist=true;
    repeat(i,Q){
      if(s[cur]==t[i]){
        cur += 2*(d[i]=='R')-1;
        if(cur==N+1){
          exist=false;
          break;
        }
      }
    }
    if(exist){
      low=mid;
    }else{
      high=mid;
    }
  }
  ans -= N-low;
  cout<<ans<<endl;
  return 0;
}
