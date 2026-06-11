#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int f(int s){
    if(s % 2 == 0) return s/2;
    else return s*3 + 1;
}

int main(void){
    int N, K; cin >> N >> K;
    //各種類の代表を知りたいのは確か
    //上からK個取ると美味しさは最大化する
    //美味しさを犠牲に種類数を増やしていく
    //2個以上あるものの中で,最も価値の低いものから新たな種類に置き換えていく
    //置き換えていく種類は,より価値の高いものを優先する -> そのまま商品の走査を続ければいい
    vector<pair<ll, int>> A(N);
    rep(i, N){
        int t; ll d; cin >> t >> d; t--;
        A[i] = make_pair(d, t);
    }
    sort(A.begin(), A.end(), greater<pair<ll, int>>());

    ll ans = 0, acc = 0;
    set<int> chose; //既に選んだやつ
    vector<ll> change_list;
    rep(i, K){
        if(chose.count(A[i].second) == 0) chose.insert(A[i].second);
        else change_list.push_back(A[i].first);
        ans += A[i].first;
    }
    ans += chose.size()*chose.size();

    sort(change_list.begin(), change_list.end(), greater<ll>());

    acc = ans;
    for(int i = K; i < N && change_list.size() > 0; i++){
        if(chose.count(A[i].second) == 0){
            int sabun = chose.size()*2 + 1;
            chose.insert(A[i].second);
            acc = acc + sabun - (change_list.back() - A[i].first);
            ans = max(ans, acc);
            change_list.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}