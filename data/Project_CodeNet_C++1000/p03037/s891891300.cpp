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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>> n >> m;
    int l = 1, r= n;
    for(int i = 0; i < m; i++)
    {
        int L, R;
        cin >> L >> R;
        l = max(L, l);
        r = min(r, R);
    }
    if(l > r)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << r - l + 1 << endl;
    return 0;
}