#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

void Warshall_Floyd (vector<vector<ll>>& distance){
    ll n = distance.size();
    for(ll i = 0; i < n; i++) distance[i][i] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                distance[j][k] = min(distance[j][i]+distance[i][k],distance[j][k]);
            }
        }
    }
}

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<ll>> d(10,vector<ll>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> d[i][j]; 
        }
    }
    Warshall_Floyd(d);
    int a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == -1) continue;
            else ans += d[a[i][j]][1];
        }
    }
    cout << ans << endl;
    return 0;
}