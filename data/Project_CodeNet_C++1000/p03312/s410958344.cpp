#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    int N;
    ll sum = 0;
    cin >> N;
    vector<ll> A(N),B(N+1);
    // B[i] := i 番目までの合計 (1-indexed)
    // [i,j] := B[j] - B[i-1];(1-indexed)
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    rep(i,N){
        B[i+1] = B[i] + A[i];
    }
    ll ok = 1e18;
    ll ng = -1;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        // mid が達成可能かどうかを調べる
        //真ん中の境界を決める
        // a,b,c,dの4つに区間を分ける
        // a+b の平均になるようにaを決めて
        // bは a+b - a で出せる
        //左側は[1,i]で右側は[i+1,N]とすると
        ll a[2],b[2],c[2],d[2];
        bool can = 0;
        for(int i=2;i<=N-2;i++){
            ll left = B[i];
            ll right = sum - left;
            //leftの中で真ん中になるような境界を求める
            // p は 左の区間で 合計が平均以上となる最初のindex
            int p = lower_bound(ALL(B),left/2) - B.begin();
            if(p == i)p--;
            if(p == 1)p++;
            a[0] = B[p-1];
            b[0] = left - a[0];
            a[1] = B[p];
            b[1] = left - a[1];
            p = lower_bound(ALL(B),left + right/2) - B.begin();
            if(p == i+1)p++;
            if(p == N)p--;
            c[0] = B[p] - left;
            c[1] = B[p-1] - left;
            d[0] = right - c[0];
            d[1] = right - c[1];
            // ab のとり方が2通り
            // cd のとり方が2通り
            //合計4パターンで達成可能かどうかを調べる
            rep(j,2)rep(k,2){
                if(max({a[j],b[j],c[k],d[k]}) - min({a[j],b[j],c[k],d[k]}) <= mid)can = 1;
            }
            if(can)break;
        }
        if(can)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}