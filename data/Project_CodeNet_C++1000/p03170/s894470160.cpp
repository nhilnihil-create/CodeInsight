#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
ll mod=1e9+7;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactice problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output

int main()
{ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll dp[k+1];
    for (int j = 0; j < k+1; ++j)
    {
        dp[j]=1;
    }

    for (int i = 0; i < k+1; ++i)
    {
        ll fg=0;
        for (int j = 0; j < n; ++j)
        {
            if((i-a[j])>=0){
                if(dp[i-a[j]]==1){
                    fg=1;
                    break;
                }
            }
        }
        if(fg==1){
            dp[i]=2;
        }
    }

    if(dp[k]==1){
        cout<<"Second";
    }
    else{
        cout<<"First";
    }

    return 0;
}
