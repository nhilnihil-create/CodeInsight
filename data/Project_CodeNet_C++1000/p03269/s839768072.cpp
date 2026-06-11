#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l;
    cin >> l;

    int tmp = l;
    int n = 0;
    while(tmp > 0)
    {
        tmp >>= 1;
        n++;
    }
    int cur = n-2;
    int cand = pow(2, cur);
    int bound = pow(2, n-1);
    vector<vector<int>> edge;
    for(int i = 1; i < n; i++)
    {
        if(l - cand >= bound)
        {
            edge.push_back({n-i, n, l-cand});
            l -= cand;
        }
        cand >>= 1; 
    }

    cout << n << " " << 2*(n-1) + (int)edge.size() << endl;
    int x = 1;
    for(int i = 1; i < n; i++)
    {
        cout << i << " " << i+1 << " " << 0 << endl;
        cout << i << " " << i+1 << " " << x << endl;
        x *= 2;
    }
    for(int i = 0; i < edge.size(); i++)
    {
        cout << edge[i][0] << " " << edge[i][1] << " " << edge[i][2] << endl;
    }
}
