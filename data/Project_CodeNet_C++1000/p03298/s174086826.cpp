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
#include <fstream>


#define f first
#define s second
#define pb push_back
#define lp(i,a,n) for(int (i)=(a);(i)<=(int)(n);(i)++)
#define lpd(i,n,a) for(int (i)=(n);(i)>=(a);--(i))
#define mp make_pair
#define clr(a, b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define eps 1e-8
#define infi 1000000007
#define infll 2000000000000000000ll
#define MX 1000000
#define X real()
#define Y imag()
#define left(i) i<<1
#define right(i) (i<<1)|1
#define polar(r,t) ((r)* exp(point(0,(t))))
#define length(a) hypot( (a).X , (a).Y )
#define angle(a) atan2( (a).Y , (a).X )
#define vec(a,b) ( (b) - (a) )
#define dot(a,b) (conj(a)*(b)).X
#define cross(a,b) (conj(a)*(b)).Y
#define lengthsqr(a) dot(a,a)
#define reflect(V,M) (conj((V)/(M)) * (M))
//#define rotate(a, theta) (a) * (polar(1.0, (theta) ))
#define normalize(a)   ((a)/length(a))
#define ccw(a,b,c) cross(vec(a,b) , vec(a,c)) > eps
#define cosRule(a,b,c) (acos(((a)*(a)+(b)*(b)-(c)*(c))/(2*(a)*(b))))
#define cosDot(a,b) (acos(dot(a,b)/length(a)/length(b)))
#define EQ(a,b) (fabs((a) - (b)) <= eps) /* equal to */
#define NE(a,b) (fabs((a) - (b)) > eps)  /* not equal to */
#define LT(a,b) ((a) < (b) - eps)        /* less than */
#define GT(a,b) ((a) > (b) + eps)        /* greater than */
#define LE(a,b) ((a) <= (b) + eps)       /* less than or equal to */
#define GE(a,b) ((a) >= (b) - eps)       /* greater than or equal to */
#define mod1 1000500001ll
#define mod2 1000300001ll
#define base1 137ll
#define base2 31ll
#define PI acos(-1)
#define sz(a) (int) (a).size()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef long double ld;
typedef complex<ld> point;
typedef pair<point, point> line;
typedef pair<ld , point> Circle;
typedef pair<point, int> Point;


//const int N = 100003;


int n;
char str[50];
unordered_map<string , int> has;

void solve(int i, string r, string b) {
    
    
    if(i == n) {
        reverse(all(r)), reverse(all(b));
        ++has[r + "." + b];
        return;
    }
    
    solve(i+1, r+str[i], b);
    solve(i+1, r, b+str[i]);
}

ll ans;
void solve1(int i, string r, string b) {
    
    
    if(i == 2*n) {
        ans += has[b + "." + r];
        return;
    }
    
    solve1(i+1, r+str[i], b);
    solve1(i+1, r, b+str[i]);
}

int main(){
  
    scanf("%d%s",&n,str);
    
    solve(0, "", "");
    solve1(n, "", "");
    
    
    printf("%lld\n",ans);
    return 0;
}

/*
 10
 4 2
 7 4
 2 6
 2 5
 4 8
 10 3
 2 9
 9 1
 5 10
 
 */

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios::sync_with_stdio(0);cin.tie(0);