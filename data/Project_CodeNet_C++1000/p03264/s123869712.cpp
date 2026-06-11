#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin>>n;

    x = n/2;

    if(n&1){
        x++;
    }
    cout<<x*(n/2)<<endl;
    return 0;
}
