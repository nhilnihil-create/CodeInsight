#include <bits/stdc++.h>
using namespace std;

#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int64_t x, y;
    cin >> x >> y;

    int64_t div = y / x;
    int ans = 0;
    bitset<64> bit(div);
    DEBUG_LOG(div << " " << bit);
    for (auto i = 0; i < 64; i++) {
        if(bit.test(i)) ans = i;
    }

    cout << (ans + 1) << endl;
    return 0;
}