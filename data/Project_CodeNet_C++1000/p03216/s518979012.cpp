#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint n;
    cin >> n;

    string s;
    cin >> s;

    lint q;
    cin >> q;

    vector<lint> k(q);
    for(auto& elem : k)  cin >> elem;

    for(lint i=0; i<k.size(); i++) {
        deque<char> dq;
        lint ans = 0, m = 0, dm = 0, d_all = 0;
        for(lint right=0; right<n; right++) {
            if(dq.size() >= k[i]) {
                lint l = dq.front(); dq.pop_front();
                if(l == 'M')  m--;
                if(l == 'D')  d_all--, dm-=m;
            }

            lint r = s[right];
            dq.push_back(r);
            if(r == 'C')  ans += dm;
            if(r == 'M')  dm += d_all, m++;
            if(r == 'D')  d_all++;
        }

        cout << ans << endl;
    }
}