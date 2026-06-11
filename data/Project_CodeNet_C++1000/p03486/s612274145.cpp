#include <bits/stdc++.h>
using namespace std;

int main()
{
        string s1,s2;cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    int c=0;
    sort(s1.begin(),s1.end());
    for(int i=0;i<m;i++)
        for(int j=i+1;j<=m;j++)
        if(s2[i]<s2[j])
            swap(s2[i],s2[j]);
    int x=min(n,m);
    if(s1==s2)
        cout<<"No";
    else {
        for(int i=0;i<x;i++)
        if(s1[i]>s2[i])
            {
            cout<<"No";
            break;
            }
        else if(s1[i]<s2[i])
            { cout<<"Yes";
                break;
            }
        else if(s1[n-1]==s2[n-1]&&n<m)
            {
                cout<<"Yes";break;
            }
            else
            { cout<<"No";
                break;
            }
            }

    return 0;
   }