#include<bits/stdc++.h>
using namespace std;

#define ll long int 

int main()
{
    string s;
    cin>>s;
    ll l=s.length();
    ll i=0, j=l-1;
    ll cnt=0;
    while(j-i>=0)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else if(s[i]=='x')
        {
            i++;
            cnt++;
        }
        else if(s[j]=='x')
        {
            j--;
            cnt++;
        }
       else 
       {
           cout<<-1<<endl;
           return 0;
       }
    }
    cout<<cnt<<endl;



    return 0;
}