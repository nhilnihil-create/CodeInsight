#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;


int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    rep(i,n){
        rep(j,n) cin >> a[j][i];
    }
    int ans=n;
    rep(i,n){
        bool t=false;
        rep(j,n){
            rep(k,n){
                if (a[(j+i)%n][k]!=a[(k+i)%n][j]){
                    t=true;
                    ans--;
                    break;
                }
            }
            if (t) break;
        }
    }
    cout << n*ans << endl;
}
