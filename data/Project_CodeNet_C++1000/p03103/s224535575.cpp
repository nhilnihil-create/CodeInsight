#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int N,M; vector<pair<ll,int>> P;
void input()
{
    cin >> N >> M;
    for(int i=0;i<N;++i){
        ll a; int b; cin >> a >> b;
        P.emplace_back(make_pair(a,b));
    }
}

void solve()
{
    sort(P.begin(),P.end());
    ll ans=0; int i=0;
    while(M > 0 && i < N){
        if(P[i].second > M){
            ans += P[i].first * M;
            break;
        }
        else {
            ans += P[i].first * P[i].second;
            M -= P[i].second;
        }
        ++i;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}