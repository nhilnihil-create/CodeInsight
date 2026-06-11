#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,m;
    map<string,int>ss;
    string blue,red;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>blue;
        ss[blue]++;
    }
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>red;
        ss[red]--;
    }
    int res=0;
 
    map<string,int>:: iterator itr;
    for(itr=ss.begin();itr!=ss.end();itr++){
            res=max(res,itr->second);
    }
    cout<<res;
 
    return 0;
}