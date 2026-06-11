#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

        int N; cin >> N;

        vector<long long> a(N, 0);

        for (int i = 0; i < N; ++i) cin >> a[i];

        vector<long long> s(N+1, 0);

        for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

        std::sort(s.begin(), s.end());

        long long count = 0;

        long long res = 0;


        for (int i = 0; i < N+1; ++i){
                if (i > 0) {
                        if (s[i] == s[i-1]) {
                                count += 1;
                                res += count;
                        }
                        else count = 0;
                }
        }

        cout << res << endl;
}
