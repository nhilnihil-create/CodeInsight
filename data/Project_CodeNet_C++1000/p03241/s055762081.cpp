#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;

int main(void) {
    int N, M;
    int ret = 1;
    cin >> N >> M;
    for(int i=1; i*i <= M; ++i) {
        if( M % i == 0) {
            if (i <= M/N && i > ret)
                ret = i;
            if (M/i <= M/N && M/i > ret)
                ret = M/i;
        }
    }
    cout << ret << endl;

    return 0;
}
