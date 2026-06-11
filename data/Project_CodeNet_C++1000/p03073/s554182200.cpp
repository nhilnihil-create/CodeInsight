#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;ll x=0;
    cin>>s;
    for(int i=2;i<=s.size();i++){
        if(s[i-2]==s[i-1]&&s[i-1]=='0')s[i-1]='1',x++;
        else if(s[i-2]==s[i-1]&&s[i-1]=='1')s[i-1]='0',x++;
    }
    cout<<x;
}
