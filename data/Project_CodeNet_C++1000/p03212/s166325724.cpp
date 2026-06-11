#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define INF 1000000000000
#define ALL(a)  (a).begin(),(a).end()

vector<int> v;

void rekkyo(int n, int r){
    if(n == 0) {
        v.push_back(r);
        return ;
    }
    rekkyo(n-1,r * 10 + 3);
    rekkyo(n-1,r * 10 + 5);
    rekkyo(n-1,r * 10 + 7);
}

int main(){
    ll n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i <= 9; i++){
        rekkyo(i,0);
    }
    for(int i = 0; i < v.size(); i++){
        bool th,fi,se;
        th = false,fi = false,se = false;
        string hoge = to_string(v[i]);
        for(int j = 0; j < hoge.length(); j++){
            char fuga = hoge[j];
            if(fuga == '3'){
                th = true;
            }
            else if(fuga == '5'){
                fi = true;
            }
            else if(fuga == '7'){
                se = true;
            }
        }
        if(th && fi && se && v[i] <= n) ans++;
    }
    cout << ans << endl;

}