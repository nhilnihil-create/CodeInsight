#include<bits/stdc++.h>
using namespace std;
#define  ll long long int
main()
{
    int n;
    cin>>n;
    while(n%2!=0)
        n=n+n;
    cout<<n<<endl;
}
