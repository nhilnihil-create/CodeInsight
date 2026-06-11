#include<bits/stdc++.h>

using namespace std;

#define LL           long long
#define ULL          long long unsigned
#define LD           long double
#define ff              first
#define ss              second
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(LL i=0;i<n;i++)
#define RFOR(i,n)    for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(LL i=n-1;i>=0;i--)
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(LL i=a;i<=b;i++)
#define fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a)       a.begin(),a.end()
#define ABS(x)       ((x)<0?-(x):(x))
#define NL           "\n"
#define pb           push_back
#define mk              make_pair
#define pi           acos(-1.0)
#define prec(n)      fixed << setprecision(n)
#define sq(a)          (a)*(a)
#define asi          cout<<"check"<<" ";
#define all_set(arr,val) memset(arr,val,sizeof(arr))

int main()
{
    fast;
    LL i,j,k,ans=0,n,temp;
    string s;
    vector<LL>vec;
    cin>>s;
    n=s.size();
    FLR(i,n){
        if(s[i]=='W')vec.pb(i);
    }
    FLR(i,n-1){
        if(s[i]=='B'){
            auto it=upper_bound(all(vec),i);
            temp=vec.end()-it;
            //cout<<temp<<NL;
            //asi
            ans+=temp;
        }

    }
    cout<<ans;
}
