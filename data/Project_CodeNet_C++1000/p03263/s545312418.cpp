#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int h, w, odd = 0;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    vector<string> res;
    repi(i, h, 0)
    {
        repi(j, w, 0)
        {
            cin >> a[i][j];
            if (a[i][j] % 2)
                odd++;
        }
    }
    bool ok = odd % 2 == 0;
    repi(i, h, 0)
    {
        repi(j, w, 0)
        {
            if (!ok && odd == 1)
                break;
            else if(ok && odd == 0) break;
            if (i % 2 == 0)
            {
                if (i != h - 1 || j != w - 1)
                {
                    if (a[i][j] % 2)
                    {
                        if (j != w - 1)
                        {
                            a[i][j + 1]++;
                            res.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 1) + " " + to_string(j + 2));
                            if(a[i][j + 1]%2)odd--;
                            // cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << "\n";
                        }
                        else
                        {
                            a[i + 1][j]++;
                            res.push_back(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 2) + " " + to_string(j + 1));
                            if(a[i + 1][j]%2)odd--;
                            // cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << "\n";
                        }
                    }
                }
            }
            else
            {
                if (i != h - 1 || j != w - 1)
                {
                    if (a[i][w - j - 1] % 2)
                    {
                        if (j != w - 1)
                        {
                            a[i][w - j - 2]++;
                            res.push_back(to_string(i + 1) + " " + to_string(w- j) + " " + to_string(i + 1) + " " + to_string(w - j - 1));
                            if(a[i][w - j - 2]%2)odd--;
                            // cout << i + 1 << " " << w - j << " " << i + 1 << " " << w - j - 1 << "\n";
                        }
                        else
                        {
                            a[i + 1][w - j - 1]++;
                            res.push_back(to_string(i + 1) + " " + to_string(w - j) + " " + to_string(i + 2) + " " + to_string(w - j));
                            if(a[i + 1][w - j - 1]%2)odd--;
                            // cout << i + 1 << " " << w - j << " " << i + 2 << " " << w - j << "\n";
                        }
                    }
                }
            }
        }
    }
    cout << res.size() << endl;
    for(auto itr = res.begin();itr != res.end();itr++){
        cout << *itr << "\n";
    }
    return 0;
}