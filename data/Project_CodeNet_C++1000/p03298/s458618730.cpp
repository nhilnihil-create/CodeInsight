#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N;
    string S;
    cin >> N >> S;

    map<string, int> Left, Right;

    for (int bit = 0; bit < (1 << N); ++bit)
    {
        string B, R;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                B.push_back(S[i]);
            }
            else
            {
                R.push_back(S[i]);
            }
        }
        reverse(ALL(R));
        B.push_back(' ');
        B.append(R);
        Left[B]++;
    }
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        string B, R;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                B.push_back(S[i + N]);
            }
            else
            {
                R.push_back(S[i + N]);
            }
        }
        reverse(ALL(R));
        R.push_back(' ');
        R.append(B);
        Right[R]++;
    }
    int ans = 0;
    for (auto itr = Left.begin(); itr != Left.end(); ++itr)
    {
        string key = itr->first;
        // cout << key << " " << Left[key] << " " << Right[key] << endl;
        ans += Left[key] * Right[key];
    }
    cout << ans << endl;

    return 0;
}