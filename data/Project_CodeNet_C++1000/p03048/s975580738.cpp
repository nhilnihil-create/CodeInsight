#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(i,0,n+1){
        rep(j,0,n+1){
            int left = n-i*r-j*g;
            if(left>=0&&left%b==0){
                //cout<<i<<j<<endl;
                ans ++;
            }
        }
    }
    cout<<ans<<endl;

    

  return 0;
}