#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    double n,k;
    int cnt=1;
    cin >> n >> k;
    double m=k;
    while(1){
        m/=2;
        if(m<1) break;
        ++cnt;
    }
    vector<int> a(cnt+1,0);
    if(n>=k) a[0]=n-k+1;
    for(int i=1; i<=cnt; ++i){
        int x=(k-1)/pow(2,i-1);
        int y=(k-1)/pow(2,i);
        rep(j,n){
            if(x>j && y<=j) ++a[i];
        }
    }
    double res=a[0];
    for(int i=1; i<cnt+1; ++i){
        res+=a[i]/pow(2,i);
    }
    cout << fixed << setprecision(15) << (res/n) << "\n";
    return 0;
}