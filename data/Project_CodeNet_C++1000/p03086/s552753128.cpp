#include <bits/stdc++.h>
using namespace std;

int	main()
{
    string S;
    cin >> S;
    int N = S.size();
    int max_len = 0;
    set<char> ATGC_set({'A', 'T', 'G', 'C'});
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            bool is_ATGC = true;
            for (int k = i; k <= j; ++k) {
                if (!ATGC_set.count(S.at(k))) {
                    is_ATGC = false;
                    break;
                }
            }
            if (!is_ATGC)
                continue;
            int len = j - i + 1;
            if (max_len < len)
                max_len = len;
        }
    }
    cout << max_len << endl;
}
