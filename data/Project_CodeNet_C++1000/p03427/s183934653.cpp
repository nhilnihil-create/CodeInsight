#include <bits/stdc++.h>
using namespace std;

long long gcd(long x, long y)
{    if (y == 0)
        return x;
    return gcd(y, x % y);}
long long lcm(long x, long y){ return x * y / gcd(x, y);}


int main()
{
    string N;
    int ans=0;
    cin>>N;

    ans=N[0]-'1';

    ans+=(N.length()-1)*9;

    int f=1;
    for(int i=1;i<N.length();i++){
        if(N[i]!='9'){
            f=0;
            break;
        }
    }
    if(f==1)ans+=1;

    cout<<ans<<endl;

    return 0;
}