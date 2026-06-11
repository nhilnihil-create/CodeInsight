#include<bits/stdc++.h>

using namespace std;

set<int>s;

int main()
{
    int n,d;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d;
        s.insert(d);
    }
    cout<<s.size();
    return 0;
}
