#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> count_e(n, 0);
    vector<int> count_e_sum(n + 1, 0);
    vector<int> count_w(n, 0);
    vector<int> count_w_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'E')
        {
            count_e[i]++;
        }
        else if (s[i] == 'W')
        {
            count_w[i]++;
        }
        count_e_sum[i + 1] = count_e_sum[i] + count_e[i];
        count_w_sum[i + 1] = count_w_sum[i] + count_w[i];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = count_w_sum[i] + count_e_sum[n] - count_e_sum[i + 1];
    }

    int answer = *min_element(begin(ans), end(ans));

    cout << answer;
}