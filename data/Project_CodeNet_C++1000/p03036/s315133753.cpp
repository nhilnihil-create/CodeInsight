#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r,d,x;
    cin>>r>>d>>x;
    int prev=x;
    for(int i=1;i<=10;i++){
        int ans=r*prev-d;
        cout<<ans<<endl;
        prev=ans;
    }
    return 0;
}
