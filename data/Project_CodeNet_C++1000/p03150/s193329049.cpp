#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checker( string s , string a)
{
    if( s.substr(0,7) == a)
        return true;
    if( s.substr(0+s.length()-7,7)==a )
        return true;
    for( int i=1;i<=7;i++)
    {
        if( s.substr(0,i) == a.substr(0,i) )
        {
            string temp = a.substr(i,a.length()-i);
            int len = temp.length();
            if( s.substr(s.length()-len,len) == temp)
                return true;
        }
    }
    return false;
}
int main()
{
    string s;
    cin>>s;
    string a = "keyence";
    if( checker(s,a))
        cout<<"YES";
    else cout<<"NO";
}