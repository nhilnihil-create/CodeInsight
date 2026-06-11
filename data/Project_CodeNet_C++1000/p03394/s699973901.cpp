#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N;
    cin >> N;
    vector<ll> ans;
    ll sum = 0;
    if(N == 3){
        cout << "2 5 63\n";
        return 0;
    }else if(N == 4){
        cout << "2 5 20 63\n";
        return 0;
    }
    for(ll k = 0; ans.size() < N; k++){
        for(ll j : {2, 3, 4, 6}){
            if(ans.size() >= N) break;
            ans.push_back(6 * k + j);
            sum += 6 * k + j;
            sum %= 6;
        }
    }
    ll las = ans.size() - 1;
    if(sum == 2){
        if(ans[las] % 6 == 2) ans[las] += 4;
        else ans[las - 1] += 4;
    }else if(sum == 3){
        if(ans[las] % 6 == 0) ans[las] += 3;
        else ans[las - 1] += 3;
    }else if(sum == 5){
        ans[las]++;
    }
    for(ll i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}
