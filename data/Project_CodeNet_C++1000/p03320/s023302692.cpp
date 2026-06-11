#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int K;
    cin >> K;
    set<ll> st;
    for (ll i = 0; i < 1000; i++) {
        ll t = i;
        int dsum = 0;
        while (t > 0) {
            dsum += t%10;
            t /= 10;
        }
        t = i;
        while (dsum <= i) {
            if (t < 10) break;
            t = t*10+9;
            dsum += 9;
            if (t > 1e15) break;
        }
        while (t < 1e15) {
            st.insert(t);
            t = t*10+9;
            dsum += 9;
        }
    }
    auto it = st.begin();
    if ((*it) == 0) it++;
    for (int i = 0; i < K; i++) {
        cout << (*it) << endl;
        it++;
    }
    return 0;
}