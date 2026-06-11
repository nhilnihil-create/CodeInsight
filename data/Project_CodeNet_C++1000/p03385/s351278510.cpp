#include<bits/stdc++.h>
using namespace std;
 

#define     fast()              ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define     ll                  int
#define     test()              ll t; cin>>t; while(t--) 
#define     lp0(i,begin,end)    for(ll i=begin;i<end;i++)
#define     lp1(i,begin,end)    for(ll i=begin;i<=end;i++)
#define     rlp(i,begin,end)    for(ll i=end;i>=begin;i--)
#define     prec(n)             fixed<<setprecision(n)
#define     initial(a,i)        memset(a,i,sizeof(a))
#define     pb                  push_back
#define     PI                  3.1415926535897932384626433832795
#define     MOD                 1000000007
#define     F                   first
#define     S                   second
#define     all(a)              (a).begin(),(a).end()
#define     BPC(x)              __builtin_popcountll(x)
#define     gcd(a,b)            __gcd(a,b)


// Solution Function
void solution(ll compte)
{
    // cout<<compte<<"\n";
    string s;
    cin>>s;

    sort(s.begin(),s.end());
    if(s=="abc")
        cout<<"Yes\n";
    else
        cout<<"No\n";              
}

// Driver Function
int main()
{
    ll compte = 1;
    //test()
    //{
        solution(compte);
        compte++;
    //}
    return 0;
}
