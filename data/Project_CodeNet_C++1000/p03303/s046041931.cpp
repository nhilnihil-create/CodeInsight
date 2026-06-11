#include <bits/stdc++.h>

using namespace std;
int main()
{
    string g;
    cin >> g;
    int n;
    cin >> n;
    for(int w=0;w<g.size();w+=n)
    {
        cout << g[w];
    }
    cout << "\n";
    return 0;//ww
}
