#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

/*
int mid_index(int l, int r)
{
    if ((r - l) % 2 == 0)
    {
        int d = (r - l) / 2;
        return d + l;
    }
    else
    {
        int d = (r - l - 1) / 2;
        return d + l;
    }
}

long long binary_search(vector<vector<long long>> mat, long long target, int l_i, int r_i, int i)
{
    long long ans;
    while (true)
    {
        int mid = mid_index(l_i, r_i);
        if (target > mat.at(i).at(r_i))
        {
            ans = -1;
            break;
        }
        else if (target < mat.at(i).at(l_i))
        {
            ans = l_i;
            break;
        }
        else if (target > mat.at(i).at(mid))
        {
            l_i = mid;
        }
        else if (target < mat.at(i).at(mid))
        {
            r_i = mid;
        }
        else if (target == mat.at(i).at(mid))
        {
            ans = mid + 1;
            break;
        }

        if (r_i == l_i + 1)
        {
            ans = r_i;
            break;
        }
    }
    return ans;
}
*/

/*
int main()
{
    long long n, ans = 0;
    cin >> n;
    vector<vector<long long>> abc(3, vector<long long>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> abc.at(i).at(j);
        }
        sort(abc.at(i).begin(), abc.at(i).end());
    }

    vector<long long> bsmallerc(n);
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "bsmallerc:" << i << endl;
        int index = 0;
        //long long lf, rg;
        //int lf_i = 0, rg_i = n - 1;
        //index = binary_search(abc, abc.at(1).at(i), lf_i, rg_i, 2);
        index = abc.at(2).end() - upper_bound(abc.at(2).begin(), abc.at(2).end(), abc.at(1).at(i));
        cout << index << endl;
        if (index == -1)
        {
            continue;
        }
        if (i == n - 1)
        {
            bsmallerc.at(i) = n - index;
        }
        else
        {
            bsmallerc.at(i) = n - index + bsmallerc.at(i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "loop:" << i << endl;
        int ans_i = 0;
        long long b1 = abc.at(0).at(i);
        //int l_i = 0, r_i = n - 1;
        //ans_i = binary_search(abc, b1, l_i, r_i, 1);
        ans_i = abc.at(1).end() - upper_bound(abc.at(1).begin(), abc.at(1).end(), b1);
        cout << ans_i << endl;
        if (ans_i == -1)
        {
            continue;
        }
        ans += bsmallerc.at(ans_i);
    }
    cout << ans << endl;
}
*/

int main()
{
    long long n, ans = 0;
    cin >> n;
    vector<vector<long long>> abc(3, vector<long long>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> abc.at(i).at(j);
        }
        sort(abc.at(i).begin(), abc.at(i).end());
    }

    for (int i = 0; i < n; i++)
    {
        long long a, c;
        a = lower_bound(abc.at(0).begin(), abc.at(0).end(), abc.at(1).at(i)) - abc.at(0).begin();
        c = abc.at(2).end() - upper_bound(abc.at(2).begin(), abc.at(2).end(), abc.at(1).at(i));
        ans += a * c;
    }

    cout << ans << endl;
}