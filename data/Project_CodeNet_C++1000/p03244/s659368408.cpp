#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
#define MAX 100000

int main(){
    int n;
    cin >> n;

    vector<ll> v(n), m(2 * MAX + 1, 0);
    //map<P, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
        m.at(i % 2 * MAX + v.at(i))++;
        //auto itr = m.find(make_pair(i%2, v.at(i)));
        //if (itr != m.end()) m[make_pair(i%2, v.at(i))]++;
        //else m[make_pair(i%2, v.at(i))] = 1;
    }

    vector<P> p;
    for (int i = 0; i < 2 * MAX + 1; i++) p.push_back(make_pair(m.at(i), i));
    sort(p.begin(), p.end(), greater<P>());

    ll ans, max_v = 0;
    if ( (p.at(0).second + MAX) != p.at(1).second && p.at(0).second != (p.at(1).second + MAX) ) ans = accumulate(m.begin(), m.end(), 0LL) - p.at(0).first - p.at(1).first;
    else {
        ans = accumulate(m.begin(), m.end(), 0LL);
        for (int i = 0; i < 100; i++) {
            for (int j = i + 1; j < 100; j++) {
                if ( (p.at(i).second + MAX) != p.at(j).second && p.at(i).second != (p.at(j).second + MAX) ) {
                    max_v = max(max_v, p.at(i).first + p.at(j).first);
                }
            }
        }
        ans -= max_v;
    }
    
    cout << ans << endl;
    return 0;
}
