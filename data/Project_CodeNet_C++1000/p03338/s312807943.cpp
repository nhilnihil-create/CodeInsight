#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

ll cal(ll k){
    ll sum = 0;
    for (ll i = 1; i <= k; ++i)
    {
        sum += i;
    }
    if(k <= 0) return 0;
    else return sum;
}

int main() {

    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    int Max = -1;
    int tmp  = 0;

    rep(i,n-1){
        tmp = 0;
        st.insert(s[i]);
        for(auto itr = st.begin(); itr != st.end(); ++itr) {
            if(s.substr(i+1,n-i-1).find_first_of(*itr) != string::npos){
                tmp ++;
            }
        }
        Max = max(tmp,Max);
    }
    cout << Max;
    return 0;
}









