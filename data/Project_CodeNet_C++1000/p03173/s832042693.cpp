#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;

const int MAXN = 405;

ll A[MAXN], accum[MAXN];
ll cost[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    ll  x, r, l;

    for(int i=1; i<=n; i++){
        cin >> A[i];
        accum[i] = A[i] + accum[i-1];
    }

    for(int i=1; i<n; i++){
        for(int j=1; i+j<=n; j++){
            cost[j][j+i] = 1e18;
            for(int k=j; k<i+j; k++){
                cost[j][j+i] = min(cost[j][j+i], cost[j][k]+cost[k+1][j+i]);
            }
            cost[j][j+i] += (accum[j+i]-accum[j-1]);
        }
    }

    cout << cost[1][n] << '\n';

    return 0;
}

