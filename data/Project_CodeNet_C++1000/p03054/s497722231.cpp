#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}

int dsu[200005], r[200005], c[200005];

void dsu_clear(){
    for(int i = 0; i < 200004; ++i){
        dsu[i] = i; r[i] = 0;
    }
}

int find(int node){
    if(node == dsu[node]) return node;
    return dsu[node] = find(dsu[node]);
}

void combine(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;
    if(r[a] <= r[b]){
        dsu[a] = b; r[b] += r[a];
    } else if(r[b] < r[a]){
        dsu[b] = a; r[a] += r[b];
    }
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, t;
    int h, w, n, x, y; cin >> h >> w >> n >> y >> x >> s >> t;

    int up = 0, down = 0, left = 0, right = 0;

    // lets go greedy afff

    // all out on left

    int cx = x;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'L') --cx;
        if(cx <= 0){
            cout << "NO";
            return 0;
        }
        if(t[i] == 'R' && cx < w) ++cx;
    }

    cx = x;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'R') ++cx;
        //cout << cx << endl;
        if(cx > w){
            cout << "NO";
            return 0;
        }
        if(t[i] == 'L' && cx > 1) --cx;
    }

    cx = y;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'D') ++cx;
        if(cx > h){
            cout << "NO";
            return 0;
        }
        if(t[i] == 'U' && cx > 1) --cx;
    }

    cx = y;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'U') --cx;
        if(cx <= 0){
            cout << "NO";
            return 0;
        }
        if(t[i] == 'D' && cx < h) ++cx;
    }

    cout << "YES";

    return 0;

}
