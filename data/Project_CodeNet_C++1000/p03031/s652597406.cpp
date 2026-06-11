#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool isOn(int bit,int i){
    return bit & 1<<(i-1);
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> lights;
    vector<int> conditions;

    rep(i, m){
        int k; cin >> k;
        vector<int> light;
        rep(j, k){
            int s; cin >> s;
            light.push_back(s);
        }
        lights.push_back(light);
    }
    rep(i, m){
        int p; cin >> p;
        conditions.push_back(p);
    }

    int res = 0;
    for(int bit=0; bit < (1<<n); ++bit){
        int lightOn = 0;
        rep(i, lights.size()){
            int cnt_swc = 0;
            for(auto swc : lights[i]){
                if(isOn(bit, swc)) ++cnt_swc;
            }
            if(cnt_swc%2 == conditions[i]) ++lightOn;
        }
        if(lightOn == m) ++res;
    }
    cout << res << endl;
}
