#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef __beyond_TLE__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #define cerr if(true)cerr
        freopen("Eroor.txt", "w", stderr);
    #endif

    #ifndef __beyond_TLE__
        #define cerr if(false)cerr
    #endif
    string s;
    cin>>s;
    long long int cnt=0, len = s.length();
    for(long long int i=0;i<len;i++)
    {
        if(s[i]=='0'&&s[i+1]=='0')
        {
            s[i+1]='1';
            cnt++;
        }
        else if(s[i]=='1'&&s[i+1]=='1')
        {
            s[i+1]='0';
            cnt++;
        }
    }
    cout<<min(len-cnt,cnt);
    return 0;
}