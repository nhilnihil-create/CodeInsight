#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int S;
    cin >> S;
    map<int, int> list;
    list[S]++;
    while (true)
    {
        int tmp;
        if (S % 2 == 0)
            tmp = S /= 2;
        else
            tmp = S * 3 + 1;
        if (list.find(tmp) == list.end())
            list[tmp]++;

        else
        {
            cout << list.size() + 1;
            break;
        }
        S = tmp;
    }
}