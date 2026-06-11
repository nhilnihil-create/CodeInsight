#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int m,k;
  cin >> m >> k;
  if(m==0){
    if(k==0){
      cout << "0 0" << endl;
    }else{
      cout << -1 << endl;
    }
  }else if(m==1){
    if(k==0){
      cout << "0 0 1 1" << endl;
    }else{
      cout << -1 << endl;
    }
  }else{
    int mx = 1<<m;
    if(k<mx){
      rep(i,mx){
        if(i!=k)cout << i << " ";
      }
      cout << k << " ";
      rep(i,mx){
        if((mx-1-i)!=k)cout << mx-1-i << " ";
      }
      cout << k << endl;
    }else{
      cout << -1 << endl;
    }
  }
}