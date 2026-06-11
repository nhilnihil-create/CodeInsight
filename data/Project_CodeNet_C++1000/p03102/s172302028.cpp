#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    int counter = 0;
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            answer += (a * b[j]);
        }
        if (answer + c > 0)
        {
            counter++;
        }
        answer = 0;
    }
    cout << counter;
}