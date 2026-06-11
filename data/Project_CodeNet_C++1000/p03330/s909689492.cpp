#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e9
#define vec vector
#define each(i, mp) for(auto& i:mp)

int N, C, X;
int D[30][30];
int t[3][30]; //余り毎に、何色が何個あるか

int main(){
    cin >> N >> C;
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) rep(j, N){
        cin >> X;
        t[(i+j)%3][X-1]++;
    }
    int res = inf;
    rep(i, C)rep(j, C)rep(k, C){
        int sum = 0;
        if(i!=j && k!=i && k!=j){
            rep(l, C) sum += D[l][i] * t[0][l];
            rep(l, C) sum += D[l][j] * t[1][l];
            rep(l, C) sum += D[l][k] * t[2][l];
            if (sum < res) res = sum;
        }
    }
    cout << res << endl;
}