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
    int n,z,w;
    cin >> n >> z >> w;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if(n==1){
        cout << abs(w-a[0]) << endl;
        return 0;
    }
    if(abs(w-a[n-1]) > abs(a[n-1]-a[n-2])){
        cout << abs(w-a[n-1]) << endl;
    }else{
        cout << abs(a[n-1]-a[n-2]) << endl;
    }
    return 0;
}