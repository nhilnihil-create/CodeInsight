#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(void) {
    int L;
    cin >> L;

    vector< tuple<int,int,int> > g;
    for(int i=2; i<20; i++) {
        g.emplace_back(i, i+1, 0);
        g.emplace_back(i, i+1, 1 << (19-i));
    }

    for(int j=0; j<=18; j++) {
        if(L >> j & 1) {
            L ^= (1 << j);
            g.emplace_back(1, 20-j, L);
        }
    }

    if(L >> 19 & 1) {
        g.emplace_back(1, 2, 0);
        g.emplace_back(1, 2, 1<<18);
    }

    cout << "20 " << g.size() << endl;
    for(auto e: g) {
        cout << get<0>(e) << ' ' << get<1>(e) << ' ' << get<2>(e) << endl;
    }
    return 0;
}
