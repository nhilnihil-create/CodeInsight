#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 5e5 + 10;

void solve(){
    int h,w;cin >> h >> w;
    int a[h+5][w+5];
    int ans = 0;
    for(int i = 0;i<h;i++)
    for(int j = 0;j<w;j++)
        cin >> a[i][j];
    vector<pii>pos1;
    vector<pii>pos2;
    for(int i = 0;i<h;i++)
    for(int j = 0;j<w;j++){
        if(a[i][j]%2&&j+1<w){
            a[i][j]--;a[i][j+1]++;
            ans++;
            pos1.push_back({i,j});
            pos2.push_back({i,j+1});
        }
        else if(a[i][j]%2&&i+1<h){
            a[i][j]--;a[i+1][j]++;
            ans++;
            pos1.push_back({i,j});
            pos2.push_back({i+1,j});
        }
    }
    cout << ans <<endl;
    for(int i = 0;i<pos1.size();i++){
        cout << pos1[i].first+1 <<' '<<pos1[i].second+1 <<' '<<pos2[i].first+1 <<' '<<pos2[i].second+1<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}