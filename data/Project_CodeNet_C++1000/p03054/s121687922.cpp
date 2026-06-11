#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m, k, x, y;
string s1, s2;
ll x1, x2, y1, y2;

int main()
{
    cin>>n>>m>>k>>x>>y;
    cin>>s1>>s2;
    x1 = 1, y1 = 1, x2 = n, y2 = m;
    for(ll i = s1.size() - 1; i >= 0; i--)
    {
        if(s2[i] == 'R') y1--;
        else if(s2[i] == 'L') y2++;
        else if(s2[i] == 'U') x2++;
        else x1--;
        x1 = max(x1, 1LL), x2 = min(x2, n);
        y1 = max(y1, 1LL), y2 = min(y2, m);
        if(s1[i] == 'R') y2--;
        else if(s1[i] == 'L') y1++;
        else if(s1[i] == 'U') x1++;
        else x2--;
        if(x1 > x2 || y1 > y2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(x1 <= x && x <= x2 && y1 <= y && y <= y2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
