#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}



int main(){
    int H, W; cin >> H >> W;
    vii cost(10, vi(10));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> cost[i][j];
        }
    }
    vii a(H, vi(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> a[i][j];
        }
    }


    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                chmin(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }

    ll sum=0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j] == -1) continue;
            sum+=cost[a[i][j]][1];
        }
    }
    cout << sum << endl;
    return 0;
}