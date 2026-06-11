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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int id = -1;
    ll mx = 0;
    bool p = true;
    rep(i,n){
        if(abs(a[i]) > mx){
            mx = abs(a[i]);
            id = i;
            if(a[i] > 0) p = true;
            else p = false;
        }
    }
    if(id==-1){
        cout << 0 << endl;
        return 0;
    }
    vector<P> ans;
    if(p){
        rep(i,n-1){
            if(a[i]<=a[i+1]) continue;
            else{
                while(a[i]>a[i+1]){
                    a[i+1] += mx;
                    ans.push_back(P(id,i+1));
                }
                if(a[i+1] > mx){
                    mx = a[i+1];
                    id = i+1;
                }
            }
        }
    }else{
        for(int i=n-2;i>=0;i--){
            if(a[i]<=a[i+1]) continue;
            else{
                while(a[i]>a[i+1]){
                    a[i] -= mx;
                    ans.push_back(P(id,i));
                }
                if(a[i] < 0 && -a[i] > mx){
                    mx = -a[i];
                    id = i;
                }
            }
        }
    }
    cout << (int)(ans.size()) << endl;
    rep(i,ans.size()) cout << (ans[i].first+1) << " " << (ans[i].second+1) << endl;
    return 0;
}