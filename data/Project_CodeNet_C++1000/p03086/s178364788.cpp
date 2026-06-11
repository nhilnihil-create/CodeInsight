#include <bits/stdc++.h>
using namespace std;

int	main()
{
    string S;
    cin >> S;
    int N = S.size();
    int max_len = 0;
    set<char> ATGC_set({'A', 'T', 'G', 'C'});
    int i, j;
    for (i = 0; i < N; i = j + 1) {
        int len = 0;
        for (j = i; j < N; ++j) {
            if (ATGC_set.count(S.at(j)))
                ++len;
            else
                break;
        }
        if (max_len < len)
            max_len = len;
    }
    cout << max_len << endl;
}
