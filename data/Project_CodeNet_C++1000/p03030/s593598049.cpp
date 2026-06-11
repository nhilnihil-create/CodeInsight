#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, priority_queue<int>> mp;
    unordered_map<int, int> ind;
    vector<string> s;
    rep(i, n)
    {
        string city;
        int px;
        cin >> city >> px;
        s.push_back(city);
        mp[city].push(px);
        ind[px] = i + 1;
    }
    sort(s.begin(), s.end());
    rep(i, n)
    {
        while (!mp[s[i]].empty())
        {
            int x = mp[s[i]].top();
            cout << ind[x] << endl;
            mp[s[i]].pop();
        }
    }
}