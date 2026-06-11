#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> AB(N);
    for(int i = 0; i < N; i++) cin >> AB[i].fi >> AB[i].se;
    sort(all(AB));
    ll sum = 0;
    ll sum_n = 0;
    for(int i = 0; i < N; i++){
        if(sum_n + AB[i].se >= M){
            sum += AB[i].fi * (M - sum_n);
            break;
        }else{
           sum_n += AB[i].se;
           sum += AB[i].fi * AB[i].se; 
        }
    }
    cout << sum << endl;
}