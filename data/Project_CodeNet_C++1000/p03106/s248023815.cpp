#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ans;
    for(int i = 1; i < 105; i++){
        if(a % i == 0 && b % i == 0) ans.push_back(i);
    }
    cout << ans[ans.size()-k] << endl;
}