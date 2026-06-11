#include<bits/stdc++.h>
using namespace std;

int main()
{

    string m,n;
    cin>>m>>n;
    int i,ansi;bool fd=0;
    for(i=0;i<=(int)(m.size()-n.size());i++)
    { int ans=0;
        for(int j=0;j<(int)n.size();j++)
        {
            if(m[j+i]==n[j] || m[j+i]=='?')
            {
                ans++;
            }

        }
        if(ans==(int)n.size()){
            fd=1;
            ansi=i;
        }

    }
    if(fd){
        string ap="";

        for(int j=0;j<m.size();j++) {
            if (m[j] == '?')
                m[j] = 'a';

        }

     for(int j=0;j<ansi;j++)
         cout<<m[j];
        for(int j=0;j<n.size();j++)
          cout<<n[j];


for(int e=ansi+n.size();e<m.size();e++)
  cout<<m[e];
        cout<<endl;

    }else{
        cout<<"UNRESTORABLE\n";
    }

    return 0;
}
