typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,q;
    std::cin >> n>>q;
    string s;
    std::cin >> s;
    vector<char> t(q),d(q);
    for (int i = 0; i < q; i++) {
        std::cin >> t[i]>>d[i];
    }
    
    ll l = -1;
    ll r = n;
    while(r-l>1){
        ll mid = (r+l)/2;
        ll now = mid;
        bool ok = false;
        for (int i = 0; i < q; i++) {
            if(s[now]==t[i]){
                if(d[i]=='R'){
                    now++;
                }else{
                    now--;
                }
                if(now==-1){
                    ok = true;
                    break;
                }
            }
        }
        if(ok){
            l = mid;
        }else{
            r = mid;
        }
    }
    
    ll lcnt = l+1;
    // std::cout << lcnt << std::endl;
    l = -1;
    r = n;
    while(r-l>1){
        ll mid = (r+l)/2;
        ll now = mid;
        bool ok = false;
        for (int i = 0; i < q; i++) {
            if(s[n-1-now]==t[i]){
                if(d[i]=='R'){
                    now--;
                }else{
                    now++;
                }
                if(now==-1){
                    ok = true;
                    break;
                }
            }
        }
        if(ok){
            l = mid;
        }else{
            r = mid;
        }
    }
    // std::cout << l+1 << std::endl;
    std::cout << n-min(n,lcnt+l+1) << std::endl;
}
