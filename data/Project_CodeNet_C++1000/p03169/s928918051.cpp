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
int n;
double dp[305][305][305];

double solve(int a, int b, int c)
{
    if(a<0 || b<0 || c<0)
        return 0;
    if(a==0 && b==0 && c==0)
        return dp[a][b][c]=0;
    if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    double p_waste=(double)(n-(a+b+c))/(double)(a+b+c);
    dp[a][b][c]=p_waste;
    // dp[a][b][c]=p_waste/(1-p_waste);
    
    dp[a][b][c]+=(double)a*((solve(a-1,b,c)+1)/(double)(a+b+c));
    dp[a][b][c]+=(double)b*((solve(a+1,b-1,c)+1)/(double)(a+b+c));
    dp[a][b][c]+=(double)c*((solve(a,b+1,c-1)+1)/(double)(a+b+c));

    return dp[a][b][c];
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
        int one=0,two=0,three=0;
        vector<int> sushi(n);
        for(int i=0; i<305; i++){
            for(int j=0; j<305; j++){
                for(int k=0; k<305; k++)
                    dp[i][j][k]=-1;
            }
        }
        for(int i=0; i<n; i++)
        {
            cin>>sushi[i];
            if(sushi[i]==1)
                one++;
            else if(sushi[i]==2)
                two++;
            else
                three++;
        }
        cout<<setprecision(9)<<fixed;
        cout<<(solve(one,two,three));
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}