#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int N;
  cin >> N;
  int hh,nn,ww;
  erep1(h,3500){
    erep1(n,3500){
      if(4*n*h > (n+h)*N){
        if(n*h*N % (4*n*h - (n+h)*N) == 0){
          nn = n;
          hh = h;
          ww = n*h*N / (4*n*h - (n+h)*N);
          break;
        }
      }
    }
  }
  cout << hh << " " << nn << " " << ww << endl;
}