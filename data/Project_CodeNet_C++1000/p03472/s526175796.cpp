#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    long long N, H;
    cin >> N >> H;
    vector<long long> a(N),b(N);
    vector<P> v(N), u(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        v[i] = P(a[i], b[i]);
        u[i] = P(b[i], a[i]);
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    P t = v[N - 1];
    long long ans = 0;
    for(int i = N - 1; i >= 0; i--){
        if(t.first <= u[i].first){
            H -= u[i].first;
            ans++;
        }
        if(H <= 0) break;
    }
    if(H <= 0){
        cout << ans << endl;
        return 0;
    }
    cout << ans + (H + t.first - 1) / t.first << endl;
}