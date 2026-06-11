#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int sum = 0, tmp;
    vector<int> list(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        sum += ((tmp + 9) / 10) * 10;
        list[i] = tmp % 10;
        if (list[i] == 0)
            list[i] = 10;
    }
    sort(list.begin(), list.end());
    cout << sum - 10 + list[0];
}