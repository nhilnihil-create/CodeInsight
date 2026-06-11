#include<bits/stdc++.h>

using namespace std;

#define io freopen("test.txt", "r", stdin);
#define fast ios_base::sync_with_stdio(0);cin.tie(0);


#define ull unsigned long long int
#define lli long long int
#define li long int
#define ld long double

#define cout(x) cout<<x<<" "
#define coutn(x) cout<<x<<endl
#define newline cout<<endl

#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define ar array

#define pii pair<int,int>
#define pll pair<lli,lli>
#define pps pair<pair<int,int>, string>

const int MOD=1000000007;
const lli INF=1e18;
const int MX=100001;
const int N=1000000;


void solve(){

    string s,t;
    cin>>s>>t;

    int n=s.size(), m=t.size();

    vector<vector<int>>v(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[j-1]==t[i-1]){
                v[i][j]=1+v[i-1][j-1];
            }else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }

    int i=m,j=n;
    string a;
    while(i>0 && j>0){
        if(s[j-1]==t[i-1]){
            a=s[j-1]+a;
            i--;
            j--;
        }else{
            if(v[i-1][j]>v[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    cout<<a<<"\n";
    // cout<<v[m][n]<<"\n";

}


int main(){
    fast
    // #ifndef godzqa
    //     io
    // #endif

    lli t;
    // cin>>t;
    t=1;

    while(t--){
        solve();
    }
    
    return 0;
}
