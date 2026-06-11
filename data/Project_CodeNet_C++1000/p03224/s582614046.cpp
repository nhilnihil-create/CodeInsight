/// Kazuki Hoshino


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
//#define endl '\n'
typedef tree<
int,
null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;


int ans[1010][1010];

void print(int n){
    int cur=0;
    rep(i, 1, n){
        ans[i][i]=++cur;
        int k = 0;
        rep(j, i+1, n+1){
        ans[j][i]=cur+k;
        k++;
        }
        rep(j, i+1, n){
        ans[i][j]=++cur;
        }
    }

    cout << "Yes" << endl;
    cout << n+1 << endl;
    rep(i, 1, n+1){
    cout << n  << " ";
    rep(j, 1, n){
    cout << ans[i][j] << " ";
    }
    cout << endl;
    }

}


int n;

signed main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


cin >> n;

rep(i, 1, 100000 ){
    if(i*(i+1)/2 == n ){
        print(i);
        return 0;
    }
}

cout << "No" << endl;





return 0;}
///....
