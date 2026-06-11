#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(M);

    for (int i = 0; i < M; ++i)
    {
        int k;
        cin >> k;
        vec[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> vec[i][j];
            --vec[i][j];
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M; ++i)
        cin >> p[i];

    int ans = 0;
    for (int i = 0; i < (1 << N); ++i)
    {
        bool ok = true;
        for (int j = 0; j < M; ++j)
        {
            int c = 0;
            for (int id : vec[j])
            {
                if ((i >> id) & 1)
                {
                    ++c;
                }
            }
            c %= 2;
            if (c != p[j])
            {
                ok = false;
            }
        }
        if (ok)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}