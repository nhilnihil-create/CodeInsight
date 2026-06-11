#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4],k;
    cin>>a[1]>>a[2]>>a[3]>>k;
    sort(a+1,a+3+1);
    a[3]*=pow(2,k);
    cout<<a[1]+a[2]+a[3];
    return 0;
}