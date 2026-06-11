#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define P_B push_back
#define PO_B pop_back
#define E_B emplace_back
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int> >;
using VVL = vector<vector<ll> >;
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//const ll LINF = (ll)1e18 - 1;
//const int INF = 1e9 - 1;

// index が条件を満たすかどうか
bool isOK(vector<Pii> &A, int index, int key) {
    if (A[index].fi >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int L_B(vector<Pii> &A, int key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)A.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        cout << left << " ~ " << right << " : " << mid << " ||| " << isOK(A, mid, key) << endl;

        if(isOK(A, mid, key)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}



void Main(){
  ll N, M, ans=0;
  cin >> N >> M;
  vector<Pii> A(M);
  rep(i, M){
    //seにA[i],fiにB[i]を格納
    cin >> A[i].se >> A[i].fi;
  }

  sort(all(A));

  ll now = A[0].fi, count = 1;
  bool done = true;
  rep(i, M){
    if(A[i+1].fi == A[i].fi && done) continue;
    if(A[i+1].fi > A[i].fi) done = false;
    if(now <= A[i+1].se){
      count++;
      now = A[i+1].fi;
      done = true;
    }
  }

  cout << count << endl;



}

int main()
{

	Main();

  return 0;
}
