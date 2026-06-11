
/*
    Author: Shivam Shukla
    Title : DP_K.cpp
    Date : 29/08/2020   >> 20:29:07

    AtCoder Educational DP : Stones

    This is a problem based on the two players, provided they are playing optimally this game where
    they have to remove stones on the basis of what number they choose from a given array of numbers.
    The person that is unable to choose or play the chance loses.

    So this problem is kinda constructive algorithm or the searching type where we need to serach for
    the optimal move the first player will be choosing and upon our choice the things will be changing as well.
    Remember this, what move will be chosen at an instant then the optimal moves from that particular chances
    would be changing so we need to move covering all the possibilities. For each of the numbers in the 
    array, and what total stones we are talking about plays an important role here.

    Consider at an instant in the game we choose 1 as our x then whole optimality changes for the plyer 2
    while if we choose 2 as our x then the optimal move sequence is entirely different.

    Lets talk about what choices do we have related to a particular x and number of stones do we have at present.
    For each of the elements in a we would try to examine what would be the result of choosing a particular number of
    stones to decrease.

    Although our answer or the winner depends upon following three things :

    1. Optimality of the move
    2. Number of stones we are dealing with
    3. Number of possible values we have seen for picking stones.

    The condition 1 ensures the uniqness of the answer, the second condtion defines the completeness
    of the chances that players are going to take or execute. 

    So at a particular instant we have the choice to choose the number of stones to decrease and 
    any other optimal move either by player 1 or player 2 will only be based on recent number of 
    stones and recent number of x values seen.

    So depending upon this we can formulate following relation for the current solving.

    Consider a function that would return the winner of the game in the terms of 0 and 1, and that given is
    passed with 2 argyments, n and k, where the numbers and stones are represented by it. 
    Actually now we need to know that the current answer depends upon who is winning at a particulkar chnace
    before that if at that paerticular position player 1 was winning then now the player 2 will win.

    solve(n, k) = 1 ^ solve(n - 1, k - a[n]);

    But this recursion is simply absurd cuz the significance of it is pretty not much according to the
    problem, in this recursion we are once including and other time exluding the possibility but due to this
    the partiucular number at the later stage in the subtree of solve(n - 1, k) would not be used which 
    will just make the things inconsistent.

    Now lets talk of something more intuitive and reframe the problem, we just try to think that 
    whether or not A can win the game since he starts the game, so we can say if in the end if there
    is at least one move through which A can win this game then for sure he/she will take that move 
    to make that happen, and this is true becuase of the optimaklity condition we described.

    Due to the optimal moves lwe assume that whenever players play then they only consider an optimal move
    the optimal move is the move such that a move which would make them win this game if they can.
    Consider the final movement of the game this game if can be won by the player A, then it is for sure
    that he will take that move and the optimal move would only favour the optimal move according to
    present conditions. 

    It is same like who started the war and if there exist a single possibility that war can be won
    then choose the sequence of actions to win that war. 

    So lets think in this way, we have the sample space to consider the n different values of x, and 
    this value will decide what can be reduced from the given k stones. 

    Now think of a very viable point, is the number of stones is able to describe the winner ?
    Well the answer is yes, because with given the number of stones we can only have the optimal play and 
    with this optimal play there will always be a single winner.

    Lets talk of some solution now, 

    vl a(n); 
    int solve(int k) {
        if (k == 0)
            return 1;

        bool ok = true;    
        repa(i, n) 
            if (k >= a[i])
              ok &= (solve(k - a[i]) == 1);
        return !ok;      
    }

    Although this code is written in some overly concise way, but think of this in following way it is
    kind of the play when we consider all the possibilities. 

    int solve(int k) {
      if (k == 0)
        return 1;

      for (int i = 0; i < n; i++)
          if (k >= a[i])
              if (solve(k - a[i]))
                  return 0;
      return 1;          
    }
    
    This sigfnifies a very important property of this problem, optimal substructure,
    The optimal substructure gives out the things that the bigger problem can be solved using the
    answer to the smaller subproblems. These subproblems actually those which made up ther bigger problem
    at all, npw think on this very important another property 


    What is the complexity ? So if we think of the complexity then we can see that into teach of the recursion
    state we woudl consider n possibilities and get a subtraction from there and that would dresult 

    n possibilities for the further calculation, and this would result in even more complexities.
    So there is about the n ^ n possible states in total if we would consider the worst case.

    Time Complexity : O(n ** n)
    Space Complexity : O(n ** n) (Recursion Stack)

    Now just try to minimize it, lets check what is increasing the problem complexity. This complexity 
    is resulting from a relatively a smaller value k and this value must not generate this much higher complexity,
    so what is the problem lying at.

    Lets check the state for example

    a = [2, 3] and k = 7
    solve(7) = solve(5), solve(4) = solve(3), solve(2), solve(2), solve(1) = solve(0), solve(1), solve(0), solve(0)
    As we can see that there is huge and giant repetition of states forjust the value of 7 and now we can 
    actually reduce it using the memoization  

    int solve()
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
 
vi dp, a; 

int solve(int k) {

  if (dp[k] != -1)
    return dp[k];

  repa(i, sz(a)) 
    if (k >= a[i])  
        if (solve(k - a[i]) == 1) 
          dp[k] = 0;

  if (dp[k] != 0)
      dp[k] = 1;
      
  return dp[k];      
}

int32_t main(int argc,char** argv){
    fastio();
    auto tstart= clock();
 
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      freopen("error.txt","w",stderr);
    #endif   

    int n, k; cin >> n >> k;

    a.resize(n);
    repa(i, n) cin >> a[i];
    dp.resize(k + 1, -1);

    dp[0] = 1;
    cout << ((solve(k)) ? "Second" : "First") << endl;  

    cerr << setprecision(8) << fixed<<"Time elapsed: " << (double)(clock() - tstart)/CLOCKS_PER_SEC << endl; 
    return 0; 
}