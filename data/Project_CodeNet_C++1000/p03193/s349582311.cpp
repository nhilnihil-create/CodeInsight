#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int64_t n,h,w;
    cin>>n>>h>>w;

    int cnt=0;
    for(int i=0;i<n;i++){
        int64_t a,b;
        cin>>a>>b;

        if(a>=h&&b>=w)
            cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}  