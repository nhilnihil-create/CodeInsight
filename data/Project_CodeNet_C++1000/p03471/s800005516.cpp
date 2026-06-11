#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    ll y;
    cin >> n >> y;
    rep(i,0,n+1){
        rep(j,0,n-i+1){
            if(y-i*10000-j*5000==1000*(n-i-j)){
                cout<<i<<" "<<j<<" "<<n-i-j<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;

  return 0;
}