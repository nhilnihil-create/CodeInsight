#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    
    int x=0,y=0,z=0;
    rep(i,0,n){
        int p;
        cin>>p;
        if(p<=a) x++;
        else if(p<=b) y++;
        else z++;
    }
    
    cout<<min({x,y,z})<<endl;
}
