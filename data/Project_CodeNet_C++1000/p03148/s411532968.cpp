// AtCoder template
// sabaより胡蝶しのぶさんの方が可愛いのではないか？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k,t; ll d; cin >> n >> k;
    vector<vector<ll>> t_list(n);
    vector<pair<ll,int>> dish(n);
    rep(i,n){
        cin >> t >> d;
        t--;
        dish[i] = make_pair(d, t);
    }
    sort(dish.begin(), dish.end(), greater<pair<ll,int>>());
    
    rep(i,n) t_list[dish[i].second].push_back(dish[i].first);

    sort(t_list.begin(), t_list.end(), [&](vector<ll> a, vector<ll> b){
        if(a.size() == 0) return false;
        else if(b.size() == 0) return true;
        return a[0] > b[0];
    });
    
    ll d_sum = 0LL;
    vector<bool> isUsed(n, false);
    priority_queue<ll, vector<ll>, greater<ll>> disposable_que; // 取り除けるネタの美味しさを管理
    priority_queue<ll> new_sushi_que; // 新種を管理 
    ll ncnt = 0LL; // 種数
    rep(i,k){ // k個選ぶ
        if(isUsed[dish[i].second]) disposable_que.push(dish[i].first);
        else{
            ncnt++;
            isUsed[dish[i].second] = true;
        }
        d_sum += dish[i].first;
    }

    for(int i = ncnt; i < t_list.size(); ++i){
        if(t_list[i].size() > 0) new_sushi_que.emplace(t_list[i][0]);
    }

    ll ret = ncnt*ncnt + d_sum;
    while(!new_sushi_que.empty() && !disposable_que.empty()){
        d_sum += new_sushi_que.top() - disposable_que.top();
        new_sushi_que.pop(); disposable_que.pop();
        ncnt++;
        ll tmp = ncnt*ncnt + d_sum;
        ret = max(ret, tmp);
    }

    cout << ret << endl;
}