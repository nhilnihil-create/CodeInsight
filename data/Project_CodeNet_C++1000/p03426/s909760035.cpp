#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int H, W, D;
    cin >> H >> W >> D;
    vector<pair<int,int>> place(H*W);
    vector<int> cost(H*W);
    int tmp;
    for(int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> tmp; tmp--;
            place.at(tmp).first = i;
            place.at(tmp).second = j;
        }
    }
    for (int i = 0; i < H*W; i++){
        if(i < D){
            cost.at(i) = 0;
            continue;
        }
        else{
            cost.at(i) = cost.at(i-D);
            cost.at(i) += abs(place.at(i).first - place.at(i-D).first);
            cost.at(i) += abs(place.at(i).second - place.at(i-D).second);
        }
    }
    
    int Q; cin >> Q;
    int tmpl,tmpr,ans;
    for (int i = 0; i < Q; i++){
        cin >> tmpl >> tmpr; tmpl--; tmpr--;
        ans = cost.at(tmpr) - cost.at(tmpl);
        printf("%d\n", ans);
    }
    
    

}
