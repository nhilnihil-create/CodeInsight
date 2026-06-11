#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
vector<ll> ans1, ans2;

int main()
{
    cin>>n;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i + 1; j <= n; j++)
        {
            if(i + j == n / 2 * 2 + 1) continue;
            ans1.push_back(i), ans2.push_back(j);
        }
    }
    cout<<ans1.size()<<endl;
    for(ll i = 0; i < ans1.size(); i++)
    {
        cout<<ans1[i]<<' '<<ans2[i]<<'\n';
    }
    return 0;
}
