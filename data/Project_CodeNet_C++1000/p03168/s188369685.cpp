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

vector<vector<double> >dp;

vector<double> probability;

double solve(int index, int head)
{
    if(head<0)
        return 0.0;
    if(index<0)
        return head==0;
    if(dp[index][head]!=-1)
        return dp[index][head];

    dp[index][head]=(probability[index]*solve(index-1,head-1)+(1.0-probability[index])*solve(index-1,head));
    return dp[index][head];
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
        int n;
        cin>>n;
        probability.resize(n);
        cin>>probability;
        double ans=0;
        dp.resize(n,vector<double> (n+1,-1));
        for(int head=(n+1)/2; head<=n; head++)
        {
            ans+=solve(n-1,head);
        }
        cout<<setprecision(9)<<fixed;
        cout<<ans<<endl;
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}