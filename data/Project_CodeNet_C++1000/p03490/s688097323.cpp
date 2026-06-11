#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int ORIGIN = 8000;
int x, y;
string s, ans = "Yes";
vector<int> d;
bitset<16001> xbit, ybit;

int main() {
    cin >> s >> x >> y;
    d.push_back(0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') d.back()++;
        else d.push_back(0);
    }
    xbit.set(d.front()+ORIGIN);
    ybit.set(ORIGIN);
    for (int i = 1; i < d.size(); i++) {
        if(i%2 == 0) {
            xbit = (xbit << d[i]) | (xbit >> d[i]);
        } else {
            ybit = (ybit << d[i]) | (ybit >> d[i]);
        }
    }
 
    if (!xbit[x+ORIGIN] || !ybit[y+ORIGIN]) ans = "No";
    cout << ans << endl;
    
    return 0;
}