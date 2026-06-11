#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A , B;
ll fnd()
{
        ll K = A*B;
        ll hi = 1e9+7;
        ll lo = 0;
        while(hi > lo)
        {
                ll md = lo + (hi - lo + 1) / 2;
                if(md*md < K) lo = md;
                else hi = md-1;
        }
        return hi;
}
int main()
{
        ll Q;
        cin >> Q;
        while(Q--)
        {
                cin >> A >> B;
                if(A == B) {
                        cout << A + A - 2 << "\n"; continue;
                }
                ll C = fnd();
                if(C*(C+1) >= A*B) cout << C + C - 2 << "\n";
                else cout << C + C - 1 << "\n";
        }
        return 0;
}
