#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).rbegin(), (x).rend()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N,H;
    cin >> N >> H;
    vec<int> a(N);
    vec<int> b(N);
    rep(i,N) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    int maxA = a[0];
    int ans =0;
    rep(i,N){
        if(b[i]>maxA){
            H-=b[i];
            ++ans;
        } else {
            break;
        }

        if(H<=0) break;
    }
    if(H<=0) {
        cout << ans << endl;
    } else {
        ans+=((H+maxA-1)/maxA);
        cout << ans << endl;
    }
}