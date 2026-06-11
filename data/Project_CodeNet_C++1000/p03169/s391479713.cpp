/*
//https://discuss.codechef.com/t/how-to-solve-this-problem/50519/5
Here is my attempt to explain the solution in the best possible manner.
Hope this will help you and others as well :slight_smile:

First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.

Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the number of dishes with 1 sushi and N is the total number of dishes in the input.

Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.

Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1. we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3 sushi with a probability of z/N or p3. we can pick a dish with 0 sushi with a probability of (N - (x + y + z))/N or p0.

Now try to understand this :
F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)

Here we add a 1 for the current move that we are making.
(Note : if you pick a dish with 3 sushi z decreases but y increases)

This equation now becomes :
(1 - p0) F(x,y,z) = 1 + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1)

simplifies to:
F(x,y,z) = (p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1))/(1-p0)

This equation can be easily evaluated using dynamic programming :slight_smile:
However try and simplify the equation to minimize the number of divisions for higher precision.
*/
#include<bits/stdc++.h>

typedef long long int lli;
typedef long double lld;
typedef long long ll;
//Datatype
#define vi vector<int>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define vvlli vector<vector<long long int>>
#define ppi pair<int, int>
#define rppi pair<int, pair<int, int>>
#define lppi pair<pair<int, int>, int>
#define vppi vector<pair<int, int>>
#define sppi stack<pair<int int>>
#define qppi queue<pair<int, int>>
//function
#define f first
#define s second
#define pb(x) push_back(x)
#define mkp(i, j) make_pair(i, j)
#define lmkp(i,j,k) make_pair(make_pair(i,j),k)
#define rmkp(i,j,k) make_pair(i,make_pair(j,k))
//loop
#define loop(i,n) for (i = 0; i < n; ++i)
#define loops(i,k,n) for (i = k; i <= n; ++i)
#define looprev(i,k,n) for (i = k; i >= n; --i)
//Const
#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//Print
#define prd(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define prdn(n) printf("%d\n", n)
#define prln(n) printf("%lld\n", n)
#define prf(n) printf("%f", n)
//Scan
#define scd(n) scanf("%d", &n)
#define scd2(a, b) scanf("%d %d", &a, &b)
#define scd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scl(n) scanf("%lld", &n)
#define scl2(a, b) scanf("%lld %lld", &a, &b)
#define scl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scf(n) scanf("%f", &n)

using namespace std;

lld dp[301][301][301];

lld sushi(lli one, lli two, lli three, lli &N){
    if(one < 0 || two < 0 || three < 0){
        return 0;
    }
    if(one == 0 && two == 0 && three == 0){
        return 0;
    }
    if(dp[one][two][three] > 0)
        return dp[one][two][three];

    lld rem = one+two+three;

    lld exp_val = N + one*sushi(one-1, two, three, N) + two*sushi(one+1, two-1, three, N) + three*sushi(one, two+1, three-1, N);

    return dp[one][two][three] = exp_val/rem;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i, j, k, N;
    cin>>N;
    lld one = 0, two = 0, three = 0;
    loop(i, N){
        lld x = 0;
        cin>>x;
        if(x == 1)
            ++one;
        else if(x == 2)
            ++two;
        else
            ++three;
    }
    memset(dp, -1, sizeof dp);
    cout<<fixed<<setprecision(9)<<sushi(one, two, three, N)<<endl;
  return 0;
}