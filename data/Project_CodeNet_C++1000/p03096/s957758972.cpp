#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long ans[300000] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> input;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        input.push_back(a);
    }
    ans[input[0]]++;
    for(int i = 0; i < n-1; i++){
        if(input[i] != input[i+1]){
            ans[input[i+1]] += ans[input[i]];
            ans[input[i+1]] %= MOD;
        }
    }
    cout << ans[input[n-1]] << endl;
    return 0;
}