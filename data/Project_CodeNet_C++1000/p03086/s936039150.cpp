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
        int len = N - i;
        for (int j = i; j < N; ++j) {
            if (!ATGC_set.count(S.at(j))) {
                len = j - i;
                break;
            }
        }
        if (max_len < len)
            max_len = len;
    }
    cout << max_len << endl;
}
