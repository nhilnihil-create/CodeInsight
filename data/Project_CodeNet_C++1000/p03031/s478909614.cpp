#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
FO

vector<int> v[100];
int p[100];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int s;
            cin>>s;
            v[s].push_back(i);
        }
    }
    for(int i=1;i<=m;i++) cin>>p[i];
    int cnt=0;
    for(int i=0;i<(1<<n);i++){
        bool ok=true;
        int arr[m+1];
        memset(arr,0,sizeof arr);
        for(int j=1;j<=n;j++){

            if(i&(1<<(j-1))){
                for(auto e:v[j]) arr[e]++;
            }

        }
        for(int j=1;j<=m;j++) if(arr[j]%2!=p[j]) ok=false;
        if(ok) cnt++;
    }
    cout<<cnt;

    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
