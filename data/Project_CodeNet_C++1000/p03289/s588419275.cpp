#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s[0]!='A')
    {
        cout<<"WA"<<endl;
        return 0;
    }
    if(isupper(s[1])||isupper(s[s.length()-1]))
    {
        cout<<"WA"<<endl;
        return 0;
    }
    int x=0;
    for(int i=2;i<s.length()-1;i++)
    {
        if(isupper(s[i])&&s[i]!='C')
        {
        cout<<"WA"<<endl;
        return 0;
        }    
        if(s[i]=='C')
            x++;
    }
    //cout<<x<<endl;
    if(x!=1)
    {
        cout<<"WA"<<endl;
        return 0;
    }
    cout<<"AC"<<endl;
    return 0;
}