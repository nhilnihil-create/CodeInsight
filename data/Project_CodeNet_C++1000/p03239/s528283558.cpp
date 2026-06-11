#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(y<=t) a.push_back(x);
    }
    sort(a.begin(),a.end());
    if(a.size())
    {
        cout<<a[0];
    }
    else
    {
        cout<<"TLE";
    }
    return 0;
}