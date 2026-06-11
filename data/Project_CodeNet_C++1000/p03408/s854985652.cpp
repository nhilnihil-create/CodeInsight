#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n,m;
    std::cin >> n;
    std::set<std::string> st;
    std::multiset<std::string> s,t;
    rep(i,n){
        std::string si;
        std::cin >> si;
        s.insert(si);
        st.insert(si);
    }
    std::cin >> m;
    rep(i,m){
        std::string ti;
        std::cin >> ti;
        t.insert(ti);
        //st.insert(ti);
    }

    int ans = 0;
    for(auto itr=st.begin(); itr!=st.end(); itr++){
        int buf = s.count(*itr);
        buf -= t.count(*itr);
        ans = std::max(ans, buf);
    }
    std::cout << ans << "\n";
    return 0;
}