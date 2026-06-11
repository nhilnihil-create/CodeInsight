#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<ll> num;

    //ランレングス圧縮
    int now = 1;
    int cnt = 0;
    for(int i= 0; i<n; i++){
        if(s[i] == (char)(now + '0')) cnt++;
        else{
            num.push_back(cnt);
            cnt = 1;
            now ^= 1;
        }
    }

    if(cnt != 0) num.push_back(cnt);
    if(num.size() %2 == 0) num.push_back(0);

    vector<ll> sum(num.size() + 1);
    rep(i,num.size()) sum[i+1] = sum[i] + num[i];

    ll K = 2*k + 1;
    ll ans = 0;
    if(K > sum.size()){
        cout << n << endl;
        return 0;
    }
    for(int i = 0; i+K < sum.size(); i+=2){
        ans = max(ans,ll(sum[i+K] - sum[i]));
    }

    cout << ans << endl;

}