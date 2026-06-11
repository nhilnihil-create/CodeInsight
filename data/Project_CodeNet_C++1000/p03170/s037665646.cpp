#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    return out;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}
int n,k;
vector<int> dp,a;

int solve(int n)
{
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=0;
    for(int i: a)
    {
        if(n>=i && solve(n-i)==0)
        {
            dp[n]=1;
            break;
        }
    }
    return dp[n];
}

int main()    
{
    #ifdef SANS
        freopen("ongoingin.txt","r",stdin);
        freopen("ongoingout.txt","w",stdout);
    #endif
    fast
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n>>k;
        dp.resize(k+1,-1);
        dp[0]=0;
        a.resize(n);
        cin>>a;
        cout<<(solve(k)?"First":"Second");
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}