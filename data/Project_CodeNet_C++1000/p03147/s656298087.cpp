#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define fore(l) for(auto && value:l)
typedef long long ll;

int main()
{
    ll size;
    cin >> size;
    vector<ll> k;
    for ( ll i = 0; i < size; i++ )
    {
        ll w;
        cin >> w;
        k.push_back( w );
    }

    ll result = 0;

    while ( true )
    {
        bool end = true;
        for ( ll i = 0; i < size; i++ )
        {
            if ( k[i] != 0 )
                end = false;
        }
        if ( end )
            break;

        ll start = 0;
        for ( start = 0; start < size; start++ )
        {
            if ( k[start] != 0 )
                break;
        }

        for ( ll i = start; i < size; i++ )
        {
            if ( k[i] == 0 )
                break;
            k[i]--;
        }
        result++;
    }
    cout << result;
}
