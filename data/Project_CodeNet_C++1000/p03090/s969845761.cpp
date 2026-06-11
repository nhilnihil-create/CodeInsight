#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<pair<int,int>> ans;
    if(N%2==0){
        for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++){
            if(i+j==N+1)continue;
            else ans.push_back({i,j});
        }
    }else{
        for(int i=1;i<=N-1;i++)for(int j=i+1;j<=N-1;j++){
            if(i+j==N)continue;
            else ans.push_back({i,j});
        }
        for(int i=1;i<=N;i++)if(i==N)continue;
        else ans.push_back({i,N});
    }
    cout << ans.size() << endl;
    for(auto x:ans)cout << x.first << " " << x.second << endl;
}