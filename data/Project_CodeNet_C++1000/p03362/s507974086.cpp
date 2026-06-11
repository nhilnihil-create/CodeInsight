#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

vector<int> prime;
void setPrime() {
    for (int i=2; i<=55555; i++) {
        bool ok = true;
        for (int e: prime) {
            if (i%e==0) {
                ok = false;
                break;
            }
            if (e*e>i) break;
        }
        if (ok) prime.push_back(i);
    }
}

int main(){
    int n;
    cin >> n;
    setPrime();
    for (int e: prime) {
        if (e%5==1) {
            cout << e << " ";
            n--;
        }
        if (n==0) break;
    }
    
    return 0;
}
