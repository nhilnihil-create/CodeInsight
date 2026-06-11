#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t,x;
    cin>>t;
    set<int>ara;
    while(t--)
    {
        cin>>x;
        ara.insert(x);
    }
    cout<<ara.size()<<endl;
}
