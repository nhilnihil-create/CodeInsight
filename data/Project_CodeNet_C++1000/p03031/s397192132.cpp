#include <iostream>
using namespace std;
int ans = 0;
void test(int n, int m, int k[], int s[][11], int p[], int x, bool used[])
{
    if(x == n)
    {
        bool correct = true;
        for(int i = 0; i < m; i++)
        {
            int sub = 0;
            for(int j = 0; j < k[i]; j++)
            {
                if(used[s[i][j] - 1])
                {
                    sub++;
                }
            }
            if(sub % 2 != p[i])
            {
                correct = false;
                break;
            }
        }
        if(correct)
        {
            ans++;
        }
        return;
    }
    x++;
    test(n, m, k, s, p, x, used);
    x--;
    used[x] = true;
    x++;
    test(n, m, k, s, p, x, used);
    x--;
    used[x] = false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    bool used[n];
    for(int i = 0; i < n; i++)
    {
        used[i] = false;
    }
    int k[m], s[11][11], p[m];
    for(int i = 0; i < m; i++)
    {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++)
        {
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    test(n, m, k, s, p, 0, used);
    cout << ans << endl;
    return 0;
}
