#include <bits/stdc++.h>
using namespace std;

std::vector<long long int> enum_div(long long int n) {
    std::vector<long long int> ret;
    for(long long int i=1 ; i*i<=n ; ++i) {
        if(n%i == 0) {
            ret.push_back(i);
            if(i!=1 && i*i!=n) {
                ret.push_back(n/i);
            }
        }
    }
    ret.push_back(n);
    return ret;
}

int main() {
    long long int n, ans = 0;
    cin >> n;
    vector<long long int> div = enum_div(n);
    set<long long int> st;
    for(int i = 0 ; i < div.size(); ++i) {
        long long int x = div[i];
        st.insert(x-1);
        st.insert(x);
        st.insert(x+1);
    }
    st.erase(0);
    st.erase(1);
    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        long long int x = *itr;
        if(n/x == n%x) ans += x;
    }

    cout << ans << '\n';

    return 0;
}
