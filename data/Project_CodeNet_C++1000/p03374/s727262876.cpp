#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int N;cin >> N;
    ll C;cin >> C;
    vector<ll> x(N),v(N);
    rep(i,N){
        cin >> x[i] >> v[i];
    }
    vector<ll> sum(N+1),sumr(N+1);

    for(int i=0;i<N;i++)sum[i+1]=sum[i]+v[i];
    for(int i=N;i>0;i--)sumr[i-1]=sumr[i]+v[i-1];
    FOR(i,1,N+1)sum[i]-=x[i-1];
    rep(i,N)sumr[i]-=C-x[i];
        
    //sum[i]...[0,i)の寿司をとった時のカロリー総計
    //sumr[i]...[i,N-1]の寿司をとった時のカロリー総計
    vector<ll> best(N+1),bestr(N+1);
    for(int i=0;i<N;i++){
        best[i+1]=max(sum[i+1],best[i]);
    }
    for(int i=N;i>0;i--){
        bestr[i-1]=max(sumr[i-1],bestr[i]);
    }
    //best[i]...[0,i)まで行けるときのカロリーのmax
    //bestr[i]...[i,N-1]まで行けるときのカロリーのmax
    ll res = 0;
    FOR(i,1,N+1){
        res = max(sum[i],res);//戻らず退店
        if(i!=N)res=max(res,sum[i]-x[i-1]+bestr[i]);//戻って反対の寿司も食べる
    }
    rep(i,N){
        res = max(sumr[i],res);//戻らず退店
        if(i!=0)res=max(res,sumr[i]-(C-x[i])+best[i]);//戻って反対の寿司も食べる
    }
    // rep(i,N+1){
    //     cout << best[i] << ":" << bestr[i] << endl;
    // }
    cout << res << endl;
    return 0;
}