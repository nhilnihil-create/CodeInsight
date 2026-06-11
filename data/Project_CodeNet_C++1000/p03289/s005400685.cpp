#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l=0,i,c=0;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(islower(s[i]))
            l++;
        if(i>1&&i<s.size()-1&&s[i]=='C')
            c++;
    }
    if(s[0]=='A'&&c==1&&l==s.size()-2)
        cout<<"AC"<<endl;
    else
        cout<<"WA"<<endl;
}
