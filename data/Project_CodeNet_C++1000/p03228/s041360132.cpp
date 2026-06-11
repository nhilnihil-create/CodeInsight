#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    rep(i,k){
        if(i%2==0){
            b += a/2;
            a /= 2;
        }else{
            a += b/2;
            b /= 2;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}

