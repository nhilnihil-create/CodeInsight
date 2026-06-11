#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int o=0,e=0;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]-'0')==0)
            o++;
        else
            e++;
    }
    cout<<2*min(o,e)<<endl;
    return 0;
}
