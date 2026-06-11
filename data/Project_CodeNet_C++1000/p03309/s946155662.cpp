#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*既に塗った色の配列　tuple(親、子、その間の辺の色)の配列
  を用意
*/
struct edge{
    int to,color;
};

using Graph = vector<vector<edge>>;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<ll> B(N);
    rep(i,N){
        B[i] = A[i] - i - 1;
    }
    sort(B.begin(),B.end());
    ll b = B[N/2];
    ll sum = 0;
    rep(i,N){
        sum += abs(B[i]-b);
    }
    cout << sum << endl;
  }