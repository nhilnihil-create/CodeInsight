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

int f(int n){
    return n*(n-1)/2;
}


int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    srepn(i,1,n){
        int ni = i;
        for(int j = 2;; j++){
            if(ni==1) break;
            while(ni%j==0){
                ni/=j;
                mp[j]++;
            }
        }
    }
    ll ans = 0;
    int a2=0, a4=0, a14=0, a24=0, a74=0;
    for(auto e : mp){
        if(e.second >= 2) a2++;
        if(e.second >= 4) a4++;
        if(e.second >= 14) a14++;
        if(e.second >= 24) a24++;
        if(e.second >= 74) a74++;
    }
    ans += f(a4)*(a2-2);
    ans += a14*(a4-1);
    ans += a24*(a2-1);
    ans += a74;
    cout << ans << endl;

}