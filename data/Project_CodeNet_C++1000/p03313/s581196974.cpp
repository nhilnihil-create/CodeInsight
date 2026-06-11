#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
int A[1 << 18 + 1];
int mx1[1 << 18], mx2[1 << 18];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < (1 << N); ++i){
        cin >> A[i];
        mx1[i] = 1 << 18; 
        mx2[i] = 1 << 18; 
    }
    mx1[0] = 0;

    int ans = 0;

    auto update = [](int idx, int v){
        if(A[idx] > A[mx1[v]]) mx2[v] = mx1[v], mx1[v] = idx;
        else if(idx != mx1[v] && A[idx] > A[mx2[v]]) mx2[v] = idx;
    };

    for(int i = 1; i < (1 << N); ++i){
        mx1[i] = i;
        for(int j = 0; j < N; ++j){
            if(i >> j & 1){
                int to = i ^ 1 << j;
                update(mx1[to], i);
                update(mx2[to], i);
            }
        }
        chmax(ans, A[mx1[i]] + A[mx2[i]]);
        cout << ans << endl;
    }
    return 0;
}