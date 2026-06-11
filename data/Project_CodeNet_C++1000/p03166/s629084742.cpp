#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <bitset>
#include <utility>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <list>
#include <valarray>

using namespace std;
#define tenp3 1000
#define tenp5 100000
#define tenp6 1000000
#define tenp9 1000000000
#define infinity 100000000000000000
#define mod 1000000007

typedef long long ll;
typedef vector<long long int> vll;
typedef pair<long long int, long long int> pll;
// typedef vector< pair<long long int, long long int> > vpll;
// #define mat

#define pushb push_back
#define popb pop_back
#define F first
#define S second
#define mp make_pair

#define repe(i, a, b) for (long long int i = (long long int)(a); i < (long long int)(b); i++)
#define repv(x, y) for (auto x : y)
#define repvref(x, y) for (auto &x : y)
#define repit(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define justSort(x) sort(x.begin(), x.end())
#define justSortR(x) sort(x.rbegin(), x.rend())
#define vec(typeOfVec, nameOfVec, sizeOfVec)      \
    vector<typeOfVec> nameOfVec(sizeOfVec);       \
    for (long long int i = 0; i < sizeOfVec; i++) \
    {                                             \
        cin >> nameOfVec[i];                      \
    }
#define print(x) cout << (x) << "\n";
#define rev(x) reverse(x.begin(), x.end())
#define copy(x, y) copy(x.begin(), x.end(), back_inserter(y));
#define mat(nameOfMat, typeOFMat, rows, cols, intitialValue) vector<vector<typeOFMat>> nameOfMat(rows, vector<typeOFMat>(cols, intitialValue));
#define gmat(nameOfMat, typeOFMat, rows, cols)                             \
    vector<vector<typeOFMat>> nameOfMat(rows, vector<typeOFMat>(cols, 0)); \
    for (long long int i = 0; i < rows; i++)                               \
    {                                                                      \
        for (long long int j = 0; j < cols; j++)                           \
        {                                                                  \
            cin >> nameOfMat[i][j];                                        \
        }                                                                  \
    }
#define pmat(nameOfMat)                                         \
    for (long long int i = 0; i < nameOfMat.size(); i++)        \
    {                                                           \
        for (long long int j = 0; j < nameOfMat[0].size(); j++) \
        {                                                       \
            cout << nameOfMat[i][j] << " ";                     \
        }                                                       \
        cout << "\n";                                           \
    }                                                           \
    cout << "\n";
#define preSum(fromArray, newArray, dataType)               \
    vector<dataType> newArray(fromArray.size() + 1);        \
    newArray[0] = 0;                                        \
    for (long long int qw = 0; qw < fromArray.size(); qw++) \
    {                                                       \
        newArray[qw + 1] = newArray[qw] + fromArray[qw];    \
    }
void printx(vll &x)
{
    for (auto i = x.begin(); i != x.end(); i++)
    {
        cout << (*i) << " ";
    }
    cout << "\n";
}
void printy(vll &x)
{
    for (auto i = x.begin(); i != x.end(); i++)
    {
        cout << (*i) << "\n";
    }
}
// inline void fastsetup()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }
// void fastscan(ll &number)
// {
//     // variable to indicate sign of input number
//     bool negative = false;
//     register int c;

//     number = 0;

//     // extract current character from buffer
//     c = getchar();
//     if (c == '-')
//     {
//         // number is negative
//         negative = true;

//         // extract the next character from the buffer
//         c = getchar();
//     }

//     // Keep on extracting characters if they are integers
//     // i.e ASCII Value lies from '0'(48) to '9' (57)
//     for (; (c > 47 && c < 58); c = getchar())
//         number = number * 10 + c - 48;

//     // if scanned input has a negative sign, negate the
//     // value of the input number
//     if (negative)
//         number *= -1;
// }

// string s[tenp5+1];
vll adj[tenp5 + 5];
ll dp[tenp5 + 5];
void topoloigcalSortAction(ll v, stack<ll> &s,  vector<bool> &visited){
    visited[v]=true;
    repv(u,adj[v]){
        if(!visited[u]){
            topoloigcalSortAction(u,s,visited);
        }
    }
    s.push(v);
}
vll topoloigcalSort(ll n){
    vector<bool> visited(n+1,false);
    stack<ll> s;
    repe(i,1,n+1){
        if(!visited[i]){
            topoloigcalSortAction(i,s,visited);
        }
    }
    vll answer;
    while (!s.empty())
    {
        // cout<<s.top()<<" ";
        answer.pushb(s.top());
        s.pop();
    }
    return answer;
}
// void dfsAction(ll v, vector<bool> &visited){
//     visited[v]=true;
//     repv(u,adj[v]){
//         if(!visited[u]){
//             dfsAction(u,visited);
//         }
//     }
//     // cout<<v<<" ";
// }
// void dfs(ll n,ll v){
//     vector<bool> visited(n+1,false);
//     visited[v]=true;
//     repv(u,adj[v]){
//         if(!visited[u]){
//             dfsAction(u,visited);
//         }
//     }
// }
int solve(int tn)
{
    ll n, m, x, y, z, tpa, tpb;
    cin >> n >> m;
    repe(i, 0, m)
    {
        cin >> tpa >> tpb;
        dp[i + 1] = 0;
        adj[tpa].pushb(tpb);
        // a[tpa]=tpb;
    }
    vll ts=topoloigcalSort(n);
    vll md(n+1,0);
    repv(v,ts){
        repv(u,adj[v]){
            md[u]=max(md[u],md[v]+1);
        }
    }
    // cout<<"\n";
    // printx(ts);
    // printx(md);
    ll ans=0;
    repv(v,md){
        ans=max(ans,v);
    }
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ll t = 1;
    // cin >> t;
    repe(w, 1, t + 1)
    {
        solve(w);
    }
    return 0;
}