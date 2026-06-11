#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll N, M;
    cin >> N >> M;
    VL a(N);
    ll sum=0;
    rep(i,0,N){cin>>a[i];sum+=a[i];}
    sort(ALL(a));

    ll ans=(M-sum)/a[0] + N;
    cout << ans << endl;
    return 0;
}