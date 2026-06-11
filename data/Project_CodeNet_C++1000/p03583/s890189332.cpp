#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    ll N; cin >> N;
    ll h;
    for(ll n = 1; n <= 3500; n++){
        for(ll w = n; w <= 3500; w++){
            ll tmp = (4 * n * w - N * w - N * n);
            ll top = n * w * N;
            if(tmp > 0 && top > 0 && top % tmp == 0){
                h = top / tmp;
                if(h > 0){
                    cout << h << " " << n << " " << w << endl;
                    return 0;
                }
            }
        }
    }
}
