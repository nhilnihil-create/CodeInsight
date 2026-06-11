#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

vector<ll> node[10004];
ll score[10004];
vector<ll> c;

void dfs(ll id){
    if(score[id] != 0) return;
    score[id] = c.back();
    c.pop_back();

    fore(x, node[id]){
        dfs(x);
    }

}

int main(void){
    ll n;
    cin >> n;

    ll ma = 0;
    ll sum = 0;

    rep(i, 0, n - 1){
        ll t1, t2;
        cin >> t1 >> t2;
        t1--;
        t2--;

        node[t1].push_back(t2);
        node[t2].push_back(t1);
    }


    rep(i, 0, n){
        ll t;
        cin >> t;
        c.push_back(t);
        ma = max(ma, t);
        sum += t;
    }

    sort(c.begin(), c.end());

    ll max_node = 0;
    rep(i, 0, n){
        max_node = max(ll(node[i].size()), max_node);
    }

    dfs(max_node);

    cout << sum - ma << endl;

    rep(i, 0, n){
        cout << score[i] << " ";
    }
    cout << endl;
    return 0;
}
