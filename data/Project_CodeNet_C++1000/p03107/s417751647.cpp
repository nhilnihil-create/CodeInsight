#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MX              200005
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ull unsigned long long
#define ll long long


void add(int &a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}
int nCr(long long m, long long n){

    //6 * 5 * 4 *../ 1*2*3*...

    int ans = 1;
    for (long long i = 1; i <= n; i++){
        ans = ans * (m - i + 1) / i;
 
    }
    return ans;
}
int32_t main()
{
    //sbs();
    // int t;cin>>t;
    // while(t--){

    // }
    string s;cin>>s;
    int n=s.length();
    int one=0,zero=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(one>0){
                one--;ans+=2;
            }else {
                zero++;
            }
        }else {
            if(zero>0){
                zero--;ans+=2;
            }else {
                one++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
