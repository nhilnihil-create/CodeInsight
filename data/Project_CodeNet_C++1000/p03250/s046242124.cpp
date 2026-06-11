#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max<int>({
        10*a+b+c,
        10*b+a+c,
        10*c+a+b
    })<<endl;
}