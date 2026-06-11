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
    int m,k;
    cin >> m >> k;
    vector<int> a(1<<(m+1),0);
    if(k >= (1<<m)){
        cout << -1 << endl;
        return 0;
    }
    if(m==1&&k==0){
        rep(i,2) cout << 0 << " ";
        rep(i,2) cout << 1 << " ";
        cout << endl;
        return 0;
    }
    if(m==1&&k==1){
        cout << -1 << endl;
        return 0;
    }
    int id = 0;
    a[id++] = k;
    for(int i=0;i<(1<<m);i++){
        if(i!=k) a[id++] = i;
    }
    a[id++] = k;
    for(int i=(1<<m)-1;i>=0;i--){
        if(i!=k) a[id++] = i;
    }
    rep(i,1<<(m+1)){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}