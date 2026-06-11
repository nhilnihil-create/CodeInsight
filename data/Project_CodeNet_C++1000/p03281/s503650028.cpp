#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

void check(vector<bool> &flag, int index, int &ans)
{
    flag.at(index) = true;
    int cnt = 2;
    for (long long i = 2; i * i <= (index + 1); i++)
    {
        if ((index + 1) % i == 0)
        {
            flag.at(i) = true;
            flag.at((index + 1) / i) = true;
            if (((index + 1) / i) == i)
            {
                cnt++;
            }
            else
            {
                cnt += 2;
            }

            if (cnt > 8)
            {
                break;
            }
        }
    }
    if (cnt == 8)
    {
        ans++;
    }
}

int check_all(int num)
{
    int ans = 0;
    vector<bool> flag(num, false);
    flag.at(0) = true;
    if (num % 2 == 0)
    {
        for (int i = 0; i < num / 2; i++)
        {
            flag.at(2 * i + 1) = true;
        }
    }
    else
    {
        for (int i = 0; i < (num - 1) / 2; i++)
        {
            flag.at(2 * i + 1) = true;
        }
    }
    bool flag_all = false;
    int index = num - 1;
    while (!flag_all)
    {
        if (!flag.at(index))
        {
            check(flag, index, ans);
            index--;
        }
        else
        {
            index--;
            continue;
        }

        int count = 0;
        for (int i = 0; i < num; i++)
        {
            if (flag.at(i) == true)
            {
                count++;
            }
        }
        if (count == num)
        {
            flag_all = true;
        }
    }
    return ans;
}

int main()
{
    int num, ans;
    cin >> num;
    ans = check_all(num);
    cout << ans << endl;
    return 0;
}