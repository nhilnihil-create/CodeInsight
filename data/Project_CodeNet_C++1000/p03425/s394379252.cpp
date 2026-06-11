#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    char check[5] = {'M', 'A', 'R', 'C', 'H'};
    vector<ll> s(5, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < 5; j++)
        {
            if (temp[0] == check[j])
            {
                s[j] += 1;
                break;
            }
        }
    }
    cout << s[0] * s[1] * (s[2] + s[3] + s[4]) + s[0] * s[2] * (s[3] + s[4]) + s[0] * s[3] * s[4] +
                s[1] * s[2] * (s[3] + s[4]) + s[1] * s[3] * s[4] + s[2] * s[3] * s[4]
         << endl;
}