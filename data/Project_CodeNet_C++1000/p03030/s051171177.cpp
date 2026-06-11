#include <bits/stdc++.h>
using namespace std;
struct a{
    int k ;
    string s;
    int score;
} city[101];
bool cmp(a x,a y)
{   if(x.s == y.s)
    {
        if(x.score>y.score)
            return true;
        else
            return false;
    }
    else if( x.s<y.s)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>city[i].s>>city[i].score;
        city[i].k=i+1;
    }
    sort(city,city+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<(city[i].k)<<'\n';
    }
    return 0;
}
