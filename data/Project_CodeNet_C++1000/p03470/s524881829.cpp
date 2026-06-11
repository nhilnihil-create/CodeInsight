#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,d;
    set<int>s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>d;
        s.insert(d);
    }
    cout<<s.size()<<endl;
}
