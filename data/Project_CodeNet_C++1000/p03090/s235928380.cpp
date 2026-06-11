#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ff first
#define ss second
#define sf ss.ff
#define tt ss.ss
#define input(a) scanf("%lld",&a)
#define M 1000000007
#define inf 1<<30
#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

/*
 *Use abbreviation:
 *dsu ->Disjoint Set Union
 *bit ->Binary Indexed Tree
 *math ->Mathematical Functions(gcd,fact,bigMod,ncr)
 *test ->For test cases
 */

ll n,sm;

int main()
{
    cin>>n;
    sm=n+!(n&1);
    cout<<(n*(n-2)+(n&1))/2<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i+j==sm)
                continue;
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}

