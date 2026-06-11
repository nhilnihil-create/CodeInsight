#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n, h; cin >> n >> h;
    priority_queue<int> B;
    int a_max = 0;
    rp(i, 0, n){
        int a, b;
        scanf("%d%d", &a, &b);
        chmax(a_max, a);
        B.push(b);
    }
    int res = 0;
    int b_count = 0;
    res = h/a_max;
    if(h%a_max!=0) res++;
    
    while(!B.empty()) {
        int b = B.top(); B.pop();
        h -= b; b_count++;
        if(h > 0) {
            int a_count = h/a_max;
            if(h%a_max!=0) a_count++;
            chmin(res, a_count+b_count);
        }
        else{
            chmin(res, b_count);
            break;
        }
    }
    cout << res << endl;
    return 0;
}