#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;

ll D, G;
vector<pair<ll, ll>> V;
ll Min = 1e9;

int dfs(vector<ll> U){
    if(U.size() == D){
        //cout << U.size() << endl;
        ll Score = 0;
        ll n=0;
        for(int i = 0; i < D; i++){
            if(U[i] == 1) {
                Score += V[i].first*(i+1)*100 + V[i].second;
                n+=V[i].first;
            }
        }
        if(Score >= G) Min = min(Min, n);
        else {
            ll Sub = G-Score;
            for(int i = D-1; i >= 0; i--){
                if(U[i] == 1) continue;
                if((V[i].first-1)*(i+1)*100 >= Sub) n += ceil((double)Sub/(double)((i+1)*100));
                else if(V[i].first*(i+1)*100 + V[i].second >= Sub) n += V[i].first;
                else return 0;
                Min = min(Min, n);
                return 0;
            }
        }


        return 0;
    }
    for(int i = 0; i < 2; i++){
        vector<ll> temp = U;
        temp.push_back(i);
        dfs(temp);
    }
    return 0;
}

int main() {
    cin >> D >> G;
    V.resize(D);
    
    for(int i = 0; i < D; i++){
        ll p, c; cin >> p >> c;
        V[i] = {p, c};
    }  
    vector<ll> _ = {};
    dfs(_);
    cout << Min << endl;
    

}