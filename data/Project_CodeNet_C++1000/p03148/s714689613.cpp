#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
const ll INF =  1LL << 35;

//まずK種類のネタを選ぶことを考える。このとき選ぶネタのは各ネタを美味しさの大きい順に
//ならべた時の最大値。
//残りを大きい順に見ていきネタの種類を減らしても美味しさが大きくなるか調べる。

int main(){
    ll N,K;
    cin >> N >> K;
    vector<vector<ll> > sushi(N);
    rep(i,N){
        int t,d;cin >> t >> d;
        t--;
        sushi[t].push_back(d);
    }
    for(auto &e : sushi){
        sort(e.rbegin(),e.rend());
        if(e.empty())e.push_back(-INF);
    }
    sort(sushi.begin(),sushi.end(),[&](vector<ll> a, vector<ll> b){return a[0]>b[0];});
    //まずK種類選ぶ
    ll cur = 0;
    priority_queue<ll> que;
    rep(i,K){
        cur += sushi[i][0];
        for(int j = 1; j < sushi[i].size();j++)que.push(sushi[i][j]);
    }
    for(int i = K; i < N; i++)rep(j,sushi[i].size())que.push(sushi[i][j]);

    //最大値を更新していく
    ll res = cur + K*K;
    for(ll x = K-1; x >= 1; --x){
        ll v = sushi[x][0];
        ll w = que.top();
        if(v < w){
            que.pop();cur += w;
            que.push(v); cur -= v;
        }
        res = max(res,cur + x*x);
    }
    cout << res << endl;
    return 0;
}