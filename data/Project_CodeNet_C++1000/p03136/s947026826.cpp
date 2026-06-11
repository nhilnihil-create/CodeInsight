#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int max_l = 0;
    int sum_l = 0;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        max_l = max(max_l, l);
        sum_l += l;
    }
    if (sum_l - max_l > max_l)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}