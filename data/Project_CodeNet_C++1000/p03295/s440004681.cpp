#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin >> n >> m;
    vector< pair<int,int> > p;
    for( int i = 0; i < m; ++i )
    {
        int a,b;
        cin >> a >> b;
        p.push_back(make_pair(b,a));
    }

    sort(p.begin(),p.end());
    int z = 0; int ans = 0;
    for( int i = 0; i < m; ++i )
    {
        if( z <= p.at(i).second )
        {
            z = p.at(i).first;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

