#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n,Y;
    cin>>n>>Y;

    rep(x,n+1){
        rep(y,n+1){
            int z=n-x-y;
            if(z<0) continue;
            if(10000*x+5000*y+1000*z==Y){
                cout<<x<<" "<<y<<" "<<z<<endl;
                return 0;
            }
        }
    }

    cout<<-1<<" "<<-1<<" "<<-1<<endl;
}

