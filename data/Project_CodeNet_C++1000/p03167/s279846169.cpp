
/*
    Author: Shivam Shukla
    Title : DP_H.cpp
    Date : 27/08/2020   >> 10:51:30

    DP - H Atcoder / Grid 1

    This problem says to find the number of paths in between two extreme cells - (1, 1) to (H, W).
    We can have multiple kind of cekks in between our path from the given cells to othrs, we can have 
    either a '.' or a '#' which signify respectively the empty or allowable cell and a wall cell to which 
    we cannot pass.
    It is also given that the cells (1, 1) and (H, W) are going to be a visible cell that can be visited.
    It is important question to ask that whether these cells are OK or they can also foloow like other cells.

    In that case we have to include the cases for the blockage of these cells as well.
    If the starting and ending cells are blocked, then they cannot be visited as well, therefore not
    such paths exist between (1, 1) and (H, W) since they cannot be reached for the successful jurney between
    the given cells.

    Now here comes the things how to solve these out. 

    Brute Force Approach : 

    The most naive way for finding out the number of ways to go through the cells via the different 
    paths, here in this case our aim would be to generate the possible paths and get to know whether 
    or not they are feasible. 

    Now how can we generate all the paths for the given grid, that's simple when we try to get to all the possibilities
    we tend to use the seraching techniques like that of backtracking or branch and bound, like techniques which 
    are provided by means of the different searching techniques via the usage of these recursion beased techniques
    we can always get to know the scenes of the possible options.

    Now how to do it objectively, coming to the statement.
    Consider what moves can you take from the cells ?

    1. Right of the current cell.
    2. Down of the current cell.

    The right will be increasing the column number while the down will be increasing the row number,
    in this case let's denote the h, w be the coords of the current cell.
    Now think about when it will be the valid path ? whenever we reach the final cell, that is whenver 
    the current cell will be getting to the coords of the final cell then it would be considered the 
    correct possibility for once and all.

    Now the point comes if we continue to call recusrion then it will always be the case that we would reach 
    the end of the cell in one way or other. Then how to proceed ? 

    Remember we talked of two type of cells - Empty one and the blocked one
    Always return from the blokced one, because it is not the worthy of it to proceed any possibilites from here
    we would only call the possibility of those cells which are empty and are capapble to be walked.

    In a better way following code snippet or pseudo code snippet will do the rest.

    int count = 0;
    void correctPaths(grid, h, w) {
        if (h == H && w == W) 
            count++, return;
        if (grid[h][w] == '#)
            return;
        correctPaths(grid, h + 1, w);
        correctPaths(grid, h, w + 1);        
        return;
    }

    Things can be pretty understood now, the answer count will be the one to store all the correct paths
    in between these two cells. The count's value will be updated via the possibility that wheenever we reach the
    final cell in one way or the other.
    In case out cell is invalid we will not be proceeding any further on this matter at all.
    In any other case our cell is ready to execute the possibilities for getting to the final cells.
    Here comes the actual recursion that is done, the possibilites are explored.

    1. Down case : correctPaths(grid, h + 1, w);
    2. Right case : correctPaths(grid, h, w + 1);

    So it is pretty evident that the overall solution for the cells with the larger coords the answer
    can be expressed in terms of the smaller coords cells, these cells may be the one to get to the result for
    a particular cell.

    Now let';s talk about something even better, how about i ask tio find the number of ways to reach the cells i and j,
    then actually the cell (i, j) can be expressed in terms of 

    solve(i, j) = solve(i - 1, j) + solve(i, j - 1)

    Here it is correctly evident that for each cell this can be expressed easily but with the edge cases 
    we need to be careful while the expression remains intact as well.
    
    Due to this brute force approach we have actually arrived to a very important property which may
    lead us to an efficient solution. 

    Optimal Substructure
    Since the possibility for the bigger coords can be expressed in the terms of smaller coords therefore
    it would become, optimal substrcuture since the optimaltiy is coming from sub possibility of the current cell.

    There is one more important generalisation if we see here, again going back to our recursion we wrote.

    solve(i, j) = solve(i - 1, j) + solve(i, j - 1)

    Now just think of it in a better way 

    solve(3, 3) = solve(2, 3) + solve(3, 2) = solve(1, 3) + solve(2, 2) + solve(2, 2) + solve(3, 1)
                = solve(1, 2) + [solve(0, 3)] + solve(1, 2) + solve(2, 1) + solve(1, 2) + solve(2, 1) + solve(2, 1) + [solve(3, 0)]

    We can come to a very important property here, that the many of the recursive calls are repeated anmd that 
    increases the time and space complexity issues here, and that creates the inefficiency of this approach.

    Overlapping Subproblems

    Now at this point we have arrived to hallmarks of the DP programming paradigm, where it is pretty 
    evident that this problem can be solved using DP.

    So now lets talk of the DP states and overall ground work we need to do to solve this out.

    Now it is pretty evident that the overlapping problems are generated due to the presence of cells
    such that they are used repetedly. We have to remove the possibility here that their recursion can be restricted
    or anhilated. In order for the complete anhilation of the recursion possibilites we need to sote the 
    things out for the next call. 

    Now if we have explored all the possibilities beneath the cell (i, j) i.e, we have got the answer how 
    to proceed from here then we don't need to get the things to be called again - Memoization

    Better and efficient version of solution can be written here

    map<pair<int,int>, int> dp;
    int solve(grid, h, w) {
        if (h == H && w == W) 
            return 1;
        if (dp.count(make_pair(h, w)) 
            return dp[make_pair(h, w)];
        if (grid[h][w] == '#)
            return 0;

        dp[make_pair(h, w)] = solve(grid, h - 1, w) + solve(grid, h, w - 1);
        return dp[make_pair(h, w)];           
    }           

    This is one of the methods to write the solution, where we have written this top down approach.
    But this gives us the way to find out the states here, the states of the DP is 

    1. Row of grid 
    2. Column of grid

    Any recursion or any possibility within our solution can be identified using the folowing mentioned two states,
    these states will uniwquely define the number of ways to reach a particular cell in the most efficient 
    way possible.

    This is the problem in which the possilbilties are the answers the total possibilites are careted and dealt this way.

    A bottom up approach of writing the solution is:

    vc(vi) dp(H, vi(W)); 
    int solve(grid) {
        repa(i, W)
            dp[0][i] = (grid[0][i] == '.);
        repa(i, H)
            dp[i][0] = (grid[i][0] == '.);

        rep(i, 1, H) {
            rep(j, 1, W) {
                dp[i][j] = 0;
                if (grid[i][j] == '.')
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[H - 1][W - 1];         
    }

    In bottom up approach we are constructing the solutions using the basic states and how we areach to
    a paerticular states. 
*/

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pair<ll,ll> > vpll;
 
const int MOD=1e9+7;
const int MAX=1e5+5;
const double PI= acos(-1.0);
const long double EPS=1e-10;
const int64_t INF=1e18+10;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define trace(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vi vector<int>
#define vl vector<ll>
#define vs vector<str>
#define vc(x) vector<x>
#define mapll map<ll,ll>
#define mapib map<int,bool>
#define mapiv map<int,vector>
#define mapsi map<string,int>
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define down(i,j,k) for(ll i=j;i>=k;i--)
#define repa(i,n) for(ll i=0;i<n;i++)
#define dowa(i,n) for(ll i=n;i>=0;i--)
#define reps(i,j,k,s) for(ll i=j;i<k;i+=s)
#define downs(i,j,k,s) for(ll i=j;i>=k;i-=s)
#define trv(i,x) for(auto i:x)
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define str string 
#define dub double
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vl,greater<ll> >
#define INF(x) numeric_limits<x>::max()
 
template<typename t> t lcm(t a, t b) {return (a*b)/__gcd(a,b);}
template<typename t> t gcd(t a, t b) {return __gcd(a,b);}
template<typename t> t mul_mod(t a, t b, t m){t res=((a%m)*(b%m)%m); return res;}
template<typename t> t add_mod(t a, t b, t m){t res=((a%m)+(b%m))%m; return res;}
template<typename t> t pow_mod(t a,t b,t m) {t res=1;while(b){if(b&1) res=mul_mod(res,a,m);a=mul_mod(a,a,m), b>>=1;} return res%m;}
template<typename t> vc(t) num_vec(t num) {t res; while (num) res.pb(num%10), num/=10; return res;}
template<typename t> t vec_num(t vec) {t res=0; ll mul=1; repa(i,sz(vec)) res=vec[i]*mul, mul*=10; return res;}
 

int32_t main(int argc,char** argv){
    fastio();
    auto tstart= clock();
 
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt","w",stderr);
    #endif   

    int h, w; cin >> h >> w;
    vc(str) a(h); repa(i, h) cin >> a[i];
    vc(vl) dp(h, vl(w));

    int state = (a[0][0] == '.');
    repa(i, h)
        state &= (a[i][0] == '.'), dp[i][0] = state;

    state = (a[0][0] == '.');    
    repa(i, w) 
        state &= (a[0][i] == '.'), dp[0][i] = state;

    rep(i, 1, h) {
        rep(j, 1, w) {
            dp[i][j] = 0;
            if (a[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[h - 1][w - 1];         

    cerr << setprecision(2) << fixed<<"Time elapsed: " << (double)(clock() - tstart)/CLOCKS_PER_SEC << endl; 
    return 0; 
}