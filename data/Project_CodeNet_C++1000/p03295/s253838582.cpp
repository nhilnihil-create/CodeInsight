#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>v(m);
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        v[i] = pair(b,a);
    }
    sort(v.begin(),v.end());
    int count = 0;
    int x = 0;
    for(int i = 0; i < m; i++)
    {
        int a = v[i].second;
        int b = v[i].first;
        if(a <= x) continue;
        x = b - 1;
        count++;
    }
    cout << count << endl;
}