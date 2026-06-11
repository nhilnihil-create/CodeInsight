#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    string s;
    int maxnochange = 0;
    int nochange;
    cin >> N >> s;

    vector<int> esum(N);
    vector<int> wsum(N);
    int e = 0,w = 0;
    for(int i=0;i<N;i++) {
        if(s[i] == 'E') {
            e++;
        }
        esum[i] = e;
    }
    for(int i=N-1;i>=0;i--) {
        if(s[i] == 'W') {
            w++;
        }
        wsum[i] = w;
    }

    // 累積和を取って
//(gdb) p esum 
//$1 = std::vector of length 12, capacity 12 = {0, 1, 1, 2, 2, 3, 4, 5, 5, 5, 5, 6}
//(gdb) p wsum 
//$2 = std::vector of length 12, capacity 12 = {1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 6, 6}
    for(int i=0;i<N;i++) {
        nochange = 0;
        // 左側で右を向いている人を加算
        if(i) {
            nochange += esum[i-1];
        }

        // 右側で左を向いている人を加算
        if(i != (N-1)) {
            nochange += wsum[i+1];
        }
//printf("i:%d m:%d\n", i, maxnochange);
        if(maxnochange < nochange) {
            maxnochange = nochange;
        }
    }

    cout << N - maxnochange - 1 << endl;

    return 0;
}
