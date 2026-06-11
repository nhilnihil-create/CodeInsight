#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const ll INF = 1001001001;

int main(){
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
}
