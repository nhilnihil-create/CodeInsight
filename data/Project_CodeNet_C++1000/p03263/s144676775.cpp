#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    lint h,w;
    cin >> h >> w;
    lint ans=0;
    vector<vector<int>> v(h, vector<int>(w));
    vector<vector<int>> v2(h, vector<int>(w));
    REP(i,h){
        REP(j,w){
            cin >> v[i][j];
            v2[i][j] = v[i][j];
        }
    }
    REP(i, h)
    {
        REP(j, w)
        {
            int x = v2[i][j];
            if(x%2==1){
                int y,z;
                // y = v[i + 1][j];
                if (j != w - 1)
                {
                    z = v2[i][j + 1];
                    if (z%2==1)
                    {
                        v2[i][j + 1]++;
                        //cout << i << " " << j << " " << i << " " << j+1 << "\n";
                        ans++;
                        continue;
                    }
                    //ans++;
                }
                if (i != h - 1)
                {
                    v2[i + 1][j]++;
                    //cout << i << " " << j << " " << i + 1 << " " << j << "\n";
                    ans++;
                    continue;
                }
                if (j != w - 1)
                {
                    v2[i][j + 1]++;
                    ans++;
                }
            }else{
            }
        }
    }
    cout << ans << endl;
    REP(i, h)
    {
        REP(j, w)
        {
            int x = v[i][j];
            if (x % 2 == 1)
            {
                int y, z;
                // y = v[i + 1][j];
                if (j != w - 1)
                {
                    z = v[i][j + 1];
                    if (z % 2 == 1)
                    {
                        v[i][j + 1]++;
                        cout << i+1 << " " << j+1 << " " << i+1 << " " << j+2 << "\n";
                        continue;
                    }
                    //ans++;
                }
                if (i != h - 1)
                {
                    v[i + 1][j]++;
                    cout << i+1 << " " << j+1 << " " << i + 2 << " " << j +1 << "\n";
                    ans++;
                    continue;
                }
                if (j != w - 1)
                {
                    v[i][j + 1]++;
                    cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << "\n";
                    ans++;
                }
            }
            else
            {
                ans++;
            }
        }
    }
    return 0;
}