#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, d;
    cin >> h >> w >> d;
    P a[h*w+5];
    rep(i,h)rep(j,w){
        int p;
        cin >> p;
        a[p] = make_pair(i,j);
    }
    int u[h*w+5];
    for(int i = 0; i < d; i++){
        for(int j = i; j <= h*w; j+=d){
            if(j==i){u[j] = 0;continue;}
            u[j] = u[j-d] + abs(a[j].first-a[j-d].first)+abs(a[j].second-a[j-d].second); 
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        printf("%d\n", u[r]-u[l]);
    }
}