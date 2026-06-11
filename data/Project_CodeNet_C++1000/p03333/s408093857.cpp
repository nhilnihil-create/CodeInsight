#include <bits/stdc++.h>
using namespace std;

multiset <int> st, dr;

long long ans, act;
int pozact;

int main()
{
    int n;
    cin >> n;

    vector <pair <int, int>> v(n);

    for (auto & i : v)
        cin >> i.first >> i.second;

    for (int d(0); d <= 1; d++) {
        st.clear();
        dr.clear();

        pozact = 0, act = 0;
        for (auto i : v) {
            st.insert(i.second);
            dr.insert(i.first);
        }

        int dir = d;
        while (1) {
            if (dir == 0) { /// stanga
                if (st.empty() || *st.begin() > pozact) {
                    act += abs(pozact);
                    break;
                }
                int a = *st.begin();
                st.erase(st.begin());
                act += abs(pozact - a);
                pozact = a;
            }
            else {
                if (dr.empty() || *dr.rbegin() < pozact) {
                    act += abs(pozact);
                    break;
                }
                int a = *dr.rbegin();
                dr.erase(dr.find(a));
                act += abs(pozact - a);
                pozact = a;
            }
            dir = 1 - dir;
        }

        ans = max(ans, act);
    }

    cout << ans << '\n';
    return 0;
}
