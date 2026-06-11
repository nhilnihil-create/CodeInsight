#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll v[e];

//beginner 1999 129
/// count : 4
int n, k;
ll ans = -1e18;

void solve(int l, int r)
{
    vector<ll>cur;
    for(int i=1; i<=l; i++){
        cur.pb(v[i]);
    }
    for(int i=r; i<=n; i++){
        cur.pb(v[i]);
    }
    ll can = k - 1LL*cur.size();
    if(can < 0) return ;
    ll sum = 0;
    sort(cur.begin(), cur.end());
    for(int i=0; i<cur.size(); i++){
        if(can > 0 && cur[i] < 0){
            can --;
        }
        else{
            sum += cur[i];
        }
    }
    if(sum > ans){
        ans = sum;
        //cout << l <<" "<<r<<"\n";
    }
    return ;
}

int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=n+1; j++){
            solve(i, j);
        }
    }
    //solve(3, n)
    cout << ans;
}
