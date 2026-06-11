#include <bits/stdc++.h>
#define     __        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    __;

    int n,red=0,blue=0;

    cin >> n;

    string s;
    
    cin >> s;
    
    for( int i=0 ; i<s.size() ; i++)
    {
        if(s[i] == 'R') red++;
        
        else blue++;
    }
    
    if(red> blue) cout<<"Yes";
    
    else cout<<"No";

    return 0;
}
