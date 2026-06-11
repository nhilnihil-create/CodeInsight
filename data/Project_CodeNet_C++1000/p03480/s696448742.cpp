#include"bits/stdc++.h"
using namespace std;
string w,q;
int as=1<<30;
int main()
{
    cin>>w;
    q=w;
    for(int i=1;i<q.length();i++)
        if(q[i]!=q[i-1])
            as=min(as,max(i,int(q.length())-i));
    cout<<min(as,int(q.length()))<<endl;
    return 0;
}