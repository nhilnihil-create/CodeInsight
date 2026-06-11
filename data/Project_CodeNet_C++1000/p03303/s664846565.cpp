#include<bits/stdc++.h>
using namespace std;
main()
{
    queue<char>s;
    string ss,sss;
    int n,i,j,l;
    cin>>ss;

    cin>>n;
    l=ss.size();
    //cout<<l<<endl;
    for(i=0;i<l;i++)
    {
        s.push(ss[i]);
    }

    for(i=0;i<l;i+=n)
    {
        j=0;
        while(j<n&&!s.empty())
        {//cout<<s.front();

         if(j==0){sss+=s.front();}
         s.pop();
         j++;
        }

    }
     cout<<sss<<endl;
}
