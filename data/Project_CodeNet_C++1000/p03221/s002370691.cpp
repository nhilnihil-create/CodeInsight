#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> cities(m);
    vector<vector<int>> s(100001,vector<int>());
    for(int i = 0; i < m; ++i)
    {
        int p,y;
        cin >> p >> y;
        cities[i] = make_pair(p,y);
        s[p].push_back(y);
    }

    for(int i = 0; i < 100001; ++i)
    {
        sort(s[i].begin(),s[i].end());
    }

    cout << setfill('0');
    for(pair<int,int> c : cities)
    {
        int pnum = c.first;
        int cnum = distance(s[pnum].begin(),lower_bound(s[pnum].begin(),s[pnum].end(),c.second))+1;
        cout << setw(6) << pnum << setw(6) << cnum << endl;
    }
}