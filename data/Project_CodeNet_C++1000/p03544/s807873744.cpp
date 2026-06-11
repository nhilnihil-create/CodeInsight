#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 ;
const int INF = 1e9 + 1e5 + 2;
const int mod= 1e9+7;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
#define eps 1e-15
#define F first
#define S second
typedef long long ll;
ll fib[100006];
int main()
{
    fastIO
    fib[0]=2,fib[1]=1;

    for (int i=2; i<=100; ++i)
        fib[i]=fib[i-1]+fib[i-2];

    int n;
    cin>>n;

    cout<<fib[n];




}
