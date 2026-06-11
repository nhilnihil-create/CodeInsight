#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,C;
    cin >> N >> C;
    vector<vector<ll> > d(C, vector<ll>(C));
    rep(i,C){
        rep(j,C){
            cin >> d[i][j];
        }
    }
    vector<vector<ll> > color(N, vector<ll>(N));
    rep(i,N){
        rep(j,N){
            cin >> color[i][j];
            color[i][j]--;
        }
    }
    vector<ll> color_list1(C);
    vector<ll> color_list2(C);
    vector<ll> color_list3(C);
    rep(i,C){
        color_list1[i] = 0;
        color_list2[i] = 0;
        color_list3[i] = 0;
    }
    rep(i,N){
        rep(j,N){
            if ((i + j + 2) % 3 == 0) color_list1[color[i][j]]++;
            if ((i + j + 2) % 3 == 1) color_list2[color[i][j]]++;
            if ((i + j + 2) % 3 == 2) color_list3[color[i][j]]++;
        }
    }
    vector<ll> color1(C);
    vector<ll> color2(C);
    vector<ll> color3(C);
    
    rep(i,C){
        ll ans = 0;
        rep(j,C){
            ans += color_list1[j] * d[j][i];
        }
        color1[i] = ans;
    }
    rep(i,C){
        ll ans = 0;
        rep(j,C){
            ans += color_list2[j] * d[j][i];
        }
        color2[i] = ans;
    }
    rep(i,C){
        ll ans = 0;
        rep(j,C){
            ans += color_list3[j] * d[j][i];
        }
        color3[i] = ans;
    }
    ll ans = 10000000000;
    rep(i,C){
        rep(j,C){
            rep(k,C){
                if (i == j || j == k || k == i) continue;
                ans = min(ans, color1[i] + color2[j] + color3[k]);
            }
        }
    }
    cout << ans << endl;
}
