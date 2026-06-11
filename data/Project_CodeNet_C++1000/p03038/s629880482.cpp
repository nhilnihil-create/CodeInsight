#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int main() {
    abdelrahman010
    multiset<int> st;
    int n , m , a[N];
    pair<int , int> b[N];
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        cin >> a[i] , st.insert(a[i]);
    for(int i = 0;i < m;i++)
        cin >> b[i].second >> b[i].first;
    sort(b , b + m , greater<>());
    for(int i = 0;i < m;i++) {
        while(*st.begin() < b[i].first && b[i].second) {
            b[i].second--;
            st.erase(st.begin());
            st.insert(b[i].first);
        }
    }
    ll ans = 0;
    for(auto &i : st)
        ans += i;
    cout << ans;
    return 0;
}