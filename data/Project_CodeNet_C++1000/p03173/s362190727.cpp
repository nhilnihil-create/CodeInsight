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
vector<ll> a, pref;
vector<vector<ll> > dp;
vector<vector<bool> > visited;

ll sum(int left, int right)
{
    if(left>right)
        return LLONG_MAX;
    if(left==0)
        return pref[right];
    return pref[right]-pref[left-1];
}

ll solve(int left, int right)
{
    if(left==right)
        return dp[left][right]=0;
    if(visited[left][right])
        return dp[left][right]; 
    visited[left][right]=true;

    for(int i=left; i<right; i++)
        dp[left][right]=min(dp[left][right],solve(left,i)+solve(i+1,right)+sum(left,right));

    return dp[left][right];    
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
        cin>>n;
        a.resize(n);
        pref.resize(n,0);
        cin>>a;
        pref[0]=a[0];
        for(int i=1; i<n; i++)
            pref[i]+=(pref[i-1]+a[i]);
        dp.resize(n,vector<ll>(n,LLONG_MAX));
        visited.resize(n,vector<bool>(n,0));
        cout<<solve(0,n-1)<<endl;
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}