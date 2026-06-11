/*
#####################################################
# I will win.. maybe not immediately but definitely #
#####################################################
*/

#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cout << "> " << #x << ": " << x << endl;
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n) 	    for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,ll>>
#define pb 	push_back

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//fast I/O
#ifndef _WIN32
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define gc getchar
#define pc putchar

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

//Declare all variables and methods needed between this comment and the next one(OCD lol)
int n;
ll seq[200010],pos[200010],ans=LLONG_MAX,x;
void solve(int k){
    ll temp=0,prevTemp=0;
    int uLim=n/k;
    REP(i,uLim){
        temp+=(seq[i]*(pos[min(n,(i+1)*k)]-pos[i*k]));
        if(prevTemp>=temp)
            return ;
        else
            prevTemp=temp;
    }

    if(n%k){
        temp+=(seq[uLim]*(pos[n]-pos[uLim*k]));
        if(prevTemp>temp)
            return ;
    }

    temp+=((ll)(k+n))*x;
    ans=(temp>ans)?ans:temp;
}
//Main function
int main(){
    IOS;
    TIE;

    cin>>n>>x;

    FOR(i,1,n+1)
        cin>>pos[i];
    sort(pos+1,pos+n+1,greater<ll>());

    FOR(i,1,n+1)
        pos[i]+=pos[i-1];

    seq[0]=seq[1]=5;
    FOR(i,2,n+1)
        seq[i]=seq[i-1]+2;

    FOR(i,1,n+1)
        solve(i);

    cout<<ans<<endl;

    return 0;
}
