#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if (s[0]=='a'&&s[1]=='b'&&s[2]=='c')
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
