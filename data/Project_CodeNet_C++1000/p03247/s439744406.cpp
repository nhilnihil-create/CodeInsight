#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    vector<ll>x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        
    }
    bool flag =0;
    bool flag2 = 0;
    rep(i,n){
        if((x[i]+y[i])%2==0){
            flag = 1;
        }else{
            flag2 = 1;
        }
    }
    if(flag&&flag2){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> d(40);
    if(flag){
        d[0] = 1;
        d[1] = 1;
        for(int i=2;i<40;i++){
            d[i] = d[i-1]*2LL;
        }
    }else{
        d[0] = 1;
        d[1] = 2;
        for(int i=2;i<40;i++){
            d[i] = d[i-1]*2LL;
        }
    }
    reverse(d.begin(),d.end());
    cout << 40 << endl;
    rep(i,40){
        cout << d[i] << " ";
    }
    cout << endl;
    rep(i,n){
        ll xx = -x[i];
        ll yy = -y[i];
        string ans;
        for(int k=0;k<40;k++){
            if(abs(xx)>=abs(yy)){
                if(xx>=0){
                    xx -=d[k];
                    ans.PB('L');
                }else{
                    xx += d[k];
                    ans.PB('R');
                }
            }else{
                if(yy>=0){
                    yy -=d[k];
                    ans.PB('D');
                }else{
                    yy += d[k];
                    ans.PB('U');
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}