#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
vi pre(N), prn(N);
signed main(){
    speed;
    int t;
    cin>>t;
    prn[1]=1;
    set<int>s;
    map<int, int>pos;
    int id=0;
    for(int i = 2; i <= N; i++){
        pre[i]+=pre[i-1];
        if(!prn[i]){
            if(i*1ll*i<=N){
                for(int j = i*i; j <= N; j+=i)prn[j]++;
            }
            int d = (i+1)/2;
            if(!prn[d])pre[i]++;
        }
    }
    while(t--){
        int l, r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
    }
}
