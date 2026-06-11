#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; cin >> N;

    int cnt_AB = 0, cnt_begin_B = 0, cnt_end_A = 0, cnt_bB_eA = 0;
    for (int n = 1; n <= N; n++)
    {
        string s; cin >> s;

        if (s[0] == 'B' && s[s.size() - 1] != 'A') cnt_begin_B++;
        else if (s[0] != 'B' && s[s.size() - 1] == 'A') cnt_end_A++;
        else if (s[0] == 'B' && s[s.size() - 1] == 'A') cnt_bB_eA++;

        for (int i = 0; i <= s.size() - 2; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B') cnt_AB++;
        }
    }

    int ans;

    if (cnt_begin_B > 0 || cnt_end_A > 0)
    {
        ans = cnt_AB + cnt_bB_eA + min(cnt_begin_B, cnt_end_A);
    }
    else if (cnt_bB_eA > 0)
    {
        // (cnt_begin_B == 0 && cnt_end_A == 0 && cnt_bB_eA > 0)
        ans = cnt_AB + (cnt_bB_eA - 1);
    }
    else // (cnt_begin_B == 0 && cnt_end_A == 0 && cnt_bB_eA == 0)
    {
        ans = cnt_AB;
    }

    cout << ans << endl;
    return 0;
}