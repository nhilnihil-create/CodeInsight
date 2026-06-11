#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[3],k;

    cin>>a[0]>>a[1]>>a[2];
    cin>>k;
    sort(a,a+3);
    for(int i=1;i<=k;i++){
        a[2]=a[2]*2;
    }
    cout<<a[0]+a[1]+a[2];

    return 0;
}
