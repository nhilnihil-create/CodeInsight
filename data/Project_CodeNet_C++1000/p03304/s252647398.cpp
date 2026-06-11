#include<bits/stdc++.h>
using namespace std;

static const int INF=1e9;
static const int MOD=1000000007;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    double n,m,d; cin >> n >> m >> d;
    double ans;
    if(d==0){
        ans=(m-1)/n;
        cout << setprecision(10) << ans << endl;
    }else{
        ans+=2*(n-d)*(m-1)*1.0/(n*n);
        cout << setprecision(20) << ans << endl;
    }
    
}
