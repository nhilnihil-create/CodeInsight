#include <bits/stdc++.h>
#define INF 1e18
#define Rep(i, a, n) for (ll i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define MAX 1000000
#define ll long long
#define P pair<int,int>
#define cout_set(n) cout << setprecision(10) << (n) << endl; 
const double PI=3.14159265358979323846;
using namespace std;
const int mod = 1000000007; 
int vy[4] ={1,-1,0,0}, vx[4] = {0,0,-1,1}; //up,down,left,right 

ll lt[MAX+1]={};

signed main(){
    ll x,y; cin >> x >> y;
    int cnt=1;
    while(1){
        if(x <= y/2){
            cnt++;
            x *= 2;
        } else{
            cout << cnt << endl; 
            break;
        }
    }

    return 0;
}
