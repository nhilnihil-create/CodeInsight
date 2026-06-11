#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INTINF = 1<<30;
const ll LLINF = 1LL<<62;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};

int check(string S,int i,vector<char> T,vector<char>D){
    REP(j,T.size()){
        if (S[i]==T[j]){
            if (D[j]=='L'){
                i--;
            }else{
                i++;
            }
        }
    }
    return i;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string S;
  cin >> S;
  char t, d;
  vector<char> T,D;
  S = "#" + S + "#";
  REP(i,q){
      cin >> t >> d;
      T.push_back(t);
      D.push_back(d);
  }
  //cout << S << endl;
  int ans = 0;
    int right = n+1;
    int left = 1;
    int mid = 0;

    while(left<right){
        mid = (left+right)/2;
        if(check(S,mid,T,D)==0){
            left = mid+1;
        }else
        {
            right = mid;
        }
    }

    ans -= left;
    right = n+1;
    left = 1;
    mid = 0;
    while(left<right){
        mid = (left+right)/2;
        if(check(S,mid,T,D)!=(n+1)){
            left = mid+1;
        }else
        {
            right = mid;
        }
    }

    ans += right;
    // FOR(i,1,n+1){
    //     cout << check(S,i,T,D) << " ";
    // }
    cout << ans << endl;
}
