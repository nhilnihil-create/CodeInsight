#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
void chmin(int &a, int b) {if(a > b) a = b;}

const int mod = 1000000007;
const int inf = 1e9;

int n, A, B, C;
vi l;

int dfs(int i, int a, int b, int c){
    if(i == n){
        if(!a || !b || !c) return inf;
        return abs(A-a)+abs(B-b)+abs(C-c);
    }

    int p1 = dfs(i+1, a+l[i], b, c) + (a? 10:0);
    int p2 = dfs(i+1, a, b+l[i], c) + (b? 10:0);
    int p3 = dfs(i+1, a, b, c+l[i]) + (c? 10:0);
    int p4 = dfs(i+1, a, b, c);

    return min(p1, min(p2, min(p3, p4)));
}


int main(){
    cin >> n >> A >> B >> C;
    l.resize(n);
    rep(i,0,n){cin >> l[i];}
    cout << dfs(0,0,0,0);
}