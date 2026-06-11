#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,K,Q;
    cin >> N >> K >> Q;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    int ans = inf;
    for(int i=0;i<N;i++){
        // 最小値をa[i]とする
        // a[i]未満の数値は候補から外れるので a[i]未満で区切る
        vector<int> v;
        vector<vector<int>> g;
        map<int,int> mp;
        // 数の候補をmapに入れていく
        for(int j=0;j<N;j++){
            if(a[j]<a[i]){
                sort(ALL(v));
                if(v.size()>=K){
                    for(int i=0;i<=v.size()-K;i++){
                        mp[v[i]]++;
                    }
                }
                v.clear();
            }else if(a[j]>=a[i]){
                v.push_back(a[j]);
            }
        }
        if(v.size()>=K){
            sort(ALL(v));
            for(int i=0;i<=v.size()-K;i++){
                mp[v[i]]++;
            }
            v.clear();
        }        
        int cnt = 0;
        int now = 0;
        for(auto &x:mp){
            if(cnt>=Q)break;
            while(x.second){
                cnt++;
                x.second--;
                now = x.first;
            }
        }
        if(cnt>=Q)ans = min(abs(a[i]-now),ans);
    }
    cout << ans << endl;
}