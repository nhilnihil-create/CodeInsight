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
#define logg2 0.30102999566398119521373889472449L

typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
FO

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+2);
    ll maxx=0;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<=n;i++){
        for(int j=n+1;j>=i+1;j--){
            if(i+n-j+1>k) continue;
            vector<int> vc;
            ll sum=0;
            for(int a=1;a<=i;a++) {vc.push_back(v[a]);sum+=v[a];}
            for(int a=j;a<=n;a++) {vc.push_back(v[a]);sum+=v[a];}
            sort(vc.begin(),vc.end());
            int m=k-(i+n-j+1);
            /*
            for(auto vv:vc) cout<<vv<<" ";
            cout<<endl;
            */
            for(int a=0;a<m && a<vc.size();a++){
                if(vc[a]<0) sum-=vc[a];
            }
            maxx=max(maxx,sum);

        }
    }

    cout<<maxx;
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
