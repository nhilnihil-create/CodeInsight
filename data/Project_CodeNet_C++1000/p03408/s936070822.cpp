#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string *s = new string[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> s[i];
    }
    int M;
    cin >> M;
    string *t = new string[M];
    for (int i = 0; i < M; ++i)
    {
        cin >> t[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int plus = count(s, s + N, s[i]);
        int minus = count(t, t + M, s[i]);
        ans = max(ans, plus - minus);
    }
    cout << ans << endl;
}