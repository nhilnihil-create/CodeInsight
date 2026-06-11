#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n, h;
    cin >> n >> h;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));

    int x = b.end() - upper_bound(all(b), a.back());

    int ans = 0;
    for(int i = n-1; i >= n-x; --i){
        ans++;
        h -= b[i];
        if(h <= 0) {
            h = 0;
            break;
        }
    }

    //cout << a.back() << "\n";
    ans += ceil(h / (double)a.back());
    cout << ans << "\n";

    return 0;
}
