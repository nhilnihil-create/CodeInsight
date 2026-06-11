#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int INF = 1<<29;

void chmin(int &a, int b){if(a > b) a = b;}

int n, A, B, C;
vector<int> l;

//4^Nの全探索
int rec(int i, int a, int b, int c){
    if(i == n){
        if(!a || !b || !c) return INF;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }
    int res = rec(i+1, a, b, c);
    chmin(res, rec(i+1, a+l[i], b, c) + (a ? 10 : 0));
    chmin(res, rec(i+1, a, b+l[i], c) + (b ? 10 : 0));
    chmin(res, rec(i+1, a, b, c+l[i]) + (c ? 10 : 0));

    return res;
}

int main(){
    cin >> n >> A >> B >> C;
    l.resize(n);
    rep(i,n) cin >> l[i];
    cout << rec(0, 0, 0, 0) << endl;
}