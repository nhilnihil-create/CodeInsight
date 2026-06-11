#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,status=0,n1,n2,n;
    string s,t,f1,f2;
    cin>>s>>t;
    n=s.length();
   /* n1=s.length();
    n2=t.length();
    if(n1!=n2)
    {
        cout<<"No";
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(islower(s[i])&&islower(t[i]))
        {
            status==0
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }*/
    /*for(i=0;i<n;i++)
    {
        f1[s[i]-97]++;
        f2[t[i]-97]++;
    }
    for(i=0;i<25;i++)
    {
        if(f1[i]!=f2[i])
        {
            cout<<1;
            cout<<"No";
            return 0;
        }
    }*/
    f1=s;
    f2=t;
    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    if(f1.compare(f2)!=0)
    {
      //  cout<<1;
        cout<<"No";
        return 0;
    }
    for(i=0;i<n;i++)
    {
    //    cout<<3;
        if(s.compare(t)==0)
        {
            cout<<"Yes";
            return 0;
        }
        else
        {
            //cout<<4;
            char a=s[n-1];
            for(j=0;j<n-1;j++)
            {
              //  cout<<5;
                s[n-1-j]=s[n-2-j];
            }
            s[0]=a;
        }
    }
    if(s.compare(t)!=0)
    {
        //cout<<2;
        cout<<"No";
    }
    return 0;
}
