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
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        deque<P> dq;
        ll ans = 0;
        ll sum = 0;
        ll c = 0;
        rep(i,n){
            if(!dq.empty()){
                if(dq[0].first<=i-k){
                    sum -= dq[0].second;
                    dq.pop_front();
                }
            }

            if(s[i]=='D'){
                dq.push_back(P(i,-c));
                sum += -c;
            }else if(s[i]=='M'){
                ++c;
            }else if(s[i]=='C'){
                ans += sum + (ll)(dq.size())*c;
            }

        }
        cout << ans << endl;
    }
    return 0;
}