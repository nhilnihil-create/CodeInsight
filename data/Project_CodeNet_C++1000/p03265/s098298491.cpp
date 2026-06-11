#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<x2-(y2-y1)<<" "<<y2+(x2-x1)<<" "<<x1-(y2-y1)<<" "<<y1+(x2-x1)<<"\n";
    
}