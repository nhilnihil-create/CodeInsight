#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int a[3];cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<a[2]*10+a[1]+a[0];
}
