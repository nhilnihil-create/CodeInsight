#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<ll> cnt(200010);
    // map<int, int> B;
    rep(i, N)
    {
        cin >> A[i];
        cnt[A[i]]++;
    }
    sort(cnt.begin(), cnt.end(), ::greater<ll>());
    cnt.erase(cnt.begin(), cnt.begin()+K);
    int ans = 0;
    for(int i = 0 ; cnt[i] != 0 ; ++i)
    {
        ans += cnt[i];
    }
    // // if(S.size() < K)
    // // {
    // //     cout << 0 << endl;
    // // }
    // int l = B.size()-K;
    // sort(A.begin(), A.end(),[&](auto const& lhs, auto const& rhs) 
    //                         {
    //                             return B[lhs] < B[rhs];
    //                         } );
    // rep(i, N)
    // {
    //     cout << A[i] << "/" << B[A[i]] << ",";
    // }
    // cout << endl;
    // int ans = 0;
    // if(l > 0)
    // rep(k, l)
    // {
    //     ans += B[A[k]];
    // }
     cout << ans << endl;
        

    return 0;
}