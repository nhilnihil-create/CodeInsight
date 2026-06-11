#include <iostream>
#include <fstream>
#include <map>
using namespace std;
map<int,int> m;
string s;
int msk,bst,x,j,i,t;
int main()
{
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        x=s[i]-'a';
        msk^=(1<<x);bst=(1<<30);
        for(j=0;j<26;j++)
        {
            t=(msk^(1<<j));
            if(m[t]||t==0)
                bst=min(bst,m[t]+1);
        }
        t=msk;
        if(m[t]||t==0)
            bst=min(bst,m[t]+1);
        m[msk]=min(bst,m[msk]);
        if((!m[msk])&&msk!=0)
            m[msk]=bst;
    }
    cout<<bst;
    return 0;
}
