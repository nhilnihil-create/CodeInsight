#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<P> V(N);
    //マンハッタン距離の偶奇が一致しない場合 false

    rep(i,0,N){
        cin >> V[i].first >> V[i].second;
    }
    int dif = abs(V[0].first) + abs(V[0].second);
    rep(i,1,N){
        int d = abs(V[i].first) + abs(V[i].second);
        if(dif % 2 != d % 2){
            cout << -1 << endl;
            return 0;
        }
    }

    ll m = 33;
    vector<ll> dist(m);

    rep(i,0,m){
        dist[i] = 1LL << i;
    }    
    if(dif % 2 == 0){
        dist.insert(dist.begin(), 1);
    }
    //cout << dist.size() - m << endl;
    cout << m + (1-dif%2) << endl;
        
    rep(i,0,dist.size())cout << dist[i] << " ";cout << endl;

    rep(j,0,N){
        string ans;
        string sub;
        ll x = V[j].first, y = V[j].second;
        if(dif % 2 == 0){
            //cout << "even" << endl;
            y--;
            sub = "U";
        }
        
        for(int i = dist.size()-1;i >= (int)dist.size()-m;i--){
            bool a = (-x + y >= 0),b = (x + y >= 0);
            //cout << a << b << endl;
            if(a && b)  {
                //cout << "U" << endl;
                ans += "U";
                y -= dist[i];
            }
            if(a && !b) { 
                //cout << "L" << endl;
                ans += "L";
                x += dist[i];
            }
            if(!a && b) { 
                //cout << "R" << endl;
                ans += "R";
                x -= dist[i];
            }
            if(!a && !b){
                //cout << "D" << endl;
                ans += "D";
                y += dist[i];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << sub + ans << endl;
    }

}