#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    cin>>n>>m>>x;
    int ans1,ans2;
    ans1=ans2=0;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(a<x)
        ans1++;
        else
        ans2++;
    }
    cout<<min(ans1,ans2)<<"\n";

    
}