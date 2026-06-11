#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    b.resize(n);
    for(auto &i : b) cin >> i;
    vector <int> ans;
    while(b.size()){
        int idx = -1;
        for(int i = 0 ; i < (int)b.size() ; i++){
            if(b[i] == i + 1) idx = i;
        }
        if(idx == -1) finish(-1);
        ans.push_back(idx + 1);
        b.erase(b.begin() + idx);
    }
    reverse(ans.begin(), ans.end());
    for(auto &i : ans) cout << i << endl;
}
