#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main(void){
    using P = pair<int, long long>;
    int n;
    cin >> n;
    vector<int> h(n+1, 0), a(n+1, 0);
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=n;i++) cin >> a[i];
    long long ans = 0;
    set<P> s;
    s.insert(P(0, 0));
    for(int i=1;i<=n;i++){
        auto itr = s.upper_bound(P(h[i], 0));
        --itr;
        P tmp = P(h[i], itr->second + a[i]);
        while(1){
            itr = s.upper_bound(P(h[i], 0));
            if(itr != s.end() && itr->second < tmp.second){
                // cout << "erase : h=" << (itr->first) << " a=" << (itr->second) << endl;
                s.erase(itr);
            }else{
                break;
            }
        }
        s.insert(tmp);
        ans = max(ans, tmp.second);
        // cout << "insert: h=" << (tmp.first) << " a=" << (tmp.second) << endl;
    }
    cout << ans << endl;
}
