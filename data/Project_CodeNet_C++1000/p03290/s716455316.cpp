#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int d,g;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    vector<pair<int,pair<int,int>>> pp(d);
    rep(i,d){
        cin >> p[i] >> c[i];
        pp[i] = make_pair(c[i],make_pair(p[i],i+1));
    }
    sort(all(pp),greater<>());
    for(int i = 0;i < d-1;++i){
        for(int j = i;j < d;++j){
            if(pp[i].first==pp[j].first){
                if(pp[i].second.first > pp[j].second.first){
                    auto a = pp[i];
                    pp[i] = pp[j];
                    pp[j] = a;
                }
            }
        }
    }

    int sum=0;
    int tmp=0;
    int ans = INF;
    for(int i = 1;i < 1<<d;++i){
        sum = 0;
        tmp = 0;
        rep(j,d){
            if(i>>j&1){
                rep(k,pp[j].second.first){
                    sum += pp[j].second.second*100;
                    tmp++;
                    if(k==pp[j].second.first-1) sum += pp[j].first;
                    if(sum >= g){
                        ans = min(ans,tmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
