#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string n;
    cin>>n;
    bool ja=true;
    for(int i=1; i<n.size(); i++)
    {
        if(n[i]!='9')
            ja=false;
    }
    if(ja)
    {
        cout<<(n.size()-1)*9+n[0]-'0'<<endl;
        return 0;
    }
    cout<<(n.size()-1)*9+n[0]-'0'-1<<endl;
}
