#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c[4][4];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>c[i][j];
        }
    }
    int ans=1;
    if(c[2][1]-c[1][1]!=c[2][2]-c[1][2] || c[2][3]-c[1][3]!=c[2][2]-c[1][2]){
        ans=2;
    }
    if(c[3][1]-c[1][1]!=c[3][2]-c[1][2] || c[3][3]-c[1][3]!=c[3][2]-c[1][2]){
        ans=3;
    }
    if(c[3][1]-c[2][1]!=c[3][2]-c[2][2] || c[3][3]-c[2][3]!=c[3][2]-c[2][2]){
        ans=4;
    }
    if(c[1][1]-c[1][2]!=c[2][1]-c[2][2] || c[2][1]-c[2][2]!=c[3][1]-c[3][2]){
        ans=5;
    }
    if(c[1][1]-c[1][3]!=c[2][1]-c[2][3] || c[2][1]-c[2][3]!=c[3][1]-c[3][3]){
        ans=6;
    }
    if(c[1][3]-c[1][2]!=c[2][3]-c[2][2] || c[2][3]-c[2][2]!=c[3][3]-c[3][2]){
        ans=7;
    }
    ans==1?cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}
