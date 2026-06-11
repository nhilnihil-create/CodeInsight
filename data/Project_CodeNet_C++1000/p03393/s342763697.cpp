#include<bits/stdc++.h>
using namespace std;
const int N=30;
string s;
bool vis[30];
int main()
{
    cin>>s;
    if(s.size()<26)
    {
        for(int i=0;i<s.size();i++)
            vis[s[i]-'a']=true;
        cout<<s;
        for(int i=0;i<26;i++)
            if(!vis[i])
        {cout<<(char)(i+'a');return 0;}
    }
    else
    {
        for(int i=0;i<s.size();i++)
            vis[s[i]-'a']=true;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=s[i]-'a'+1;j<26;j++)
                if(!vis[j])
            {
                for(int k=0;k<i;k++)
                    cout<<s[k];
                cout<<(char)(j+'a');
                return 0;
            }
            vis[s[i]-'a']=false;
        }
        cout<<-1<<endl;
    }
}
