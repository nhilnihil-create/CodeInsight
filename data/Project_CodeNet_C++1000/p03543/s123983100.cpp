#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    string s;
    cin>>s;
    
    if(s[0]==s[1] && s[1]==s[2] ||  s[1]==s[2]&&s[2]==s[3])
    puts("Yes");
    else
    puts("No");
        
}