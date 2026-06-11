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
#define MOD 1000000007
vector<string> grid;
vector<vector<int> > dp;

int solve(int h, int w)
{
    if(h<0 || w<0)
        return -1;
    if(h==0 && w==0)
    {
        dp[h][w]=1;
        return 1;
    }
    if(dp[h][w]!=0)
        return dp[h][w];
    if(grid[h][w]=='#')
        return -1;
    int fst=solve(h-1,w);
    int lst=solve(h,w-1);
    if(fst==-1 && lst==-1)
        dp[h][w]=-1;
    else if(fst==-1 || lst==-1)
        dp[h][w]=max(lst,fst);
    else
        dp[h][w]=(lst+fst)%MOD;
    return dp[h][w];
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
        int h,w;
        cin>>h>>w;
        grid.resize(h);
        dp.resize(h);
        for(int i=0; i<h; i++)
        {
            dp[i].resize(w,0);
            cin>>grid[i];
        }
        int ans=solve(h-1,w-1);
        cout<<max(ans,0);
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}