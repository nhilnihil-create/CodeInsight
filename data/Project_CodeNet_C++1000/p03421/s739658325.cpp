
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
#include<set>
#include<map>
#include <unordered_map>
#include <unordered_set>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include<math.h>
#include <strings.h>



#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 300002;


int n,a,b,ans[N];


bool check(int a,int b) {
    return a == 1 && b != n;
}



int main(){
    
    scanf("%d%d%d",&n,&a,&b);
    
    if(a+b-1 > n || 1ll*a*b < n || a > n || b > n)
        return printf("-1\n"), 0;

    
    
    while (n > 0) {
        int x = min(a, n - b + 1);
        lp(i, n-x+1, n) printf("%d ",i);
        n -= x, --b;
    }

    
    
    
    lp(i, 1, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}



/*

 5 3
 1 3
 1 5
 3 6
 4 4
 2 6
 1 5 3
 1 5 4
 1 1 1

 */
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
//ios::sync_with_stdio(0);cin.tie(0);