#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    map<string,int>m;
    map<string,int>:: iterator itr;
    int n,chk1=0,chk2=0;
    cin>>n;
    cin>>s;
    char last=s[s.length()-1];
    m[s]=1;
    for(int i=1; i<n; i++)
    {
        cin>>s;
        m[s]++;
        if(chk1==0)
        {
            if(s[0]==last)
            {
                chk1=0;
            }
            else if(s[0]!=last)
            {
                chk1=1;
            }
            last=s[s.length()-1];
        }
        }
        if(chk1==1)
            cout<<"No";
        else
        {
            for(itr=m.begin();itr!=m.end();itr++){
               if(itr->second>1){
                    chk2=1;
                    break;
                }
            }
            if(chk2==0) cout<<"Yes";
            else cout<<"No";
            }
        return 0;
    }
