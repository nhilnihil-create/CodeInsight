#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = (int)s.size();
    set<string> st;
    for (int i = 0; i<n; i++) {
        string x = "";
        x += s[i];
        st.insert(x);
        for (int j = i+1; j<n; j++) {
            x += s[j];
            st.insert(x);
            if(j>i+5)break;
        }
    }
    auto it = st.begin();
    it = next(it,k-1);
    cout << *it << endl;
    return 0;
}
