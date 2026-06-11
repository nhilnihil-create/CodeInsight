#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        if(((x[i] + y[i])%2 == 0 && (x[i+1] +y[i+1])%2 == 0) 
        || ((x[i] + y[i])%2 != 0 && (x[i+1] +y[i+1])%2 != 0))
        {
            continue;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<ll> arm;
    if((x[0]+y[0]) % 2 == 0)
    {
      cout << 32 << endl;
      arm.push_back(1);  
    }
    else
    {
      cout << 31 << endl;
    }
    ll j = 1;
    for(int i = 0; i < 31; i++)
    {
        arm.push_back(j);
        j = j << 1;
    }
    reverse(arm.begin(), arm.end());
    for(int i = 0; i < arm.size()-1; i++)
    {
        cout << arm[i] << " ";
    }
    cout << arm[arm.size()-1] << endl;

    for(int i = 0; i < n; i++)
    {
        ll u = x[i] + y[i];
        ll v = x[i] - y[i];
        ll nx = 0;
        ll ny = 0;
        for(int j = 0; j < arm.size(); j++)
        {
            if(nx <= u && ny <= v)
            {
                cout << "R";
                nx += arm[j];
                ny += arm[j];
            }
            else if(nx >= u && ny >= v)
            {
                cout << "L";
                nx -= arm[j];
                ny -= arm[j];
            }
            else if(nx <= u && ny >= v)
            {
                cout << "U";
                nx += arm[j];
                ny -= arm[j];
            }
            else
            {
                cout << "D";
                nx -= arm[j];
                ny += arm[j];
            }
        }
        cout << endl;
    }
}
