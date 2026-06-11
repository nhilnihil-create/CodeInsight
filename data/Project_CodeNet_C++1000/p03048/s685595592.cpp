#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int rr = (3000+r)/r;
    int gg = (3000+g)/g;
    int cnt = 0;
    rep(i,rr){
        if(i * r > n) break;
        rep(j,gg){
            if(i*r+j*g > n) break;
            if((n-i*r-j*g)%b == 0 )cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
/*

*/