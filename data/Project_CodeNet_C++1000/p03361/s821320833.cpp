#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool search(const vector<string> &mp, int h, int w, int i, int j)
{
    bool res = true;
    if(0 <= i-1 && mp.at(i-1).at(j)=='#') res = false;
    if(i+1 < h && mp.at(i+1).at(j)=='#') res = false;
    if(0 <= j-1 && mp.at(i).at(j-1)=='#') res = false;
    if(j+1 < w && mp.at(i).at(j+1)=='#') res = false;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    for(int i=0; i<h; i++) cin >> mp.at(i);

    bool ans = true;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(mp.at(i).at(j) == '#')
            {
                if(search(mp, h, w, i, j)) ans = false;
            }
        }
    }
    cout << (ans?"Yes":"No") << '\n';
    return 0;
}