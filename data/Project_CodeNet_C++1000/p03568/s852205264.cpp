#include <bits/stdc++.h>
using namespace std;

long long gcd(long x, long y)
{    if (y == 0)
        return x;
    return gcd(y, x % y);}
long long lcm(long x, long y){ return x * y / gcd(x, y);}


int main()
{
    int N,A[110]={},odd=1,ans=1,zcnt=0;
    cin>>N;


    for(int i=1;i<=N;i++){
        ans*=3;

        cin>>A[i];
    
        if(A[i]%2==0){
            odd*=2;
        }
    }

    cout<<ans-odd<<endl;

    return 0;
}