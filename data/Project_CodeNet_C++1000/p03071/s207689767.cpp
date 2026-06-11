#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t=1;
    //cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<max(x+x-1,max(x+y,y+y-1));
        
    }
    return 0;
}