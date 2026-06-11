#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    vector<ll> Num(N); 
    vector<ll> ans;
    for(int i = 0; i < N; i++) {
        cin >> Num[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = Num.size() - 1; j >= 0; j--){
            if(Num[j] == j + 1){
            Num.erase(Num.begin() + j);
            ans.push_back(j + 1);
            break;
            }
        }
    }

    if(Num.size() != 0){
        ans.clear();
        ans.push_back(-1);
    }
    reverse(ans.begin(), ans.end());
    for(ll x : ans) cout << x << endl;

    return 0;
}