#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll ans=0, cnt = 0;
    string s;
    cin>>s;
    for(char c:s){
        if(c=='B') cnt++;
        else if(c=='W') ans += cnt;
    }
    cout<<ans;

}
