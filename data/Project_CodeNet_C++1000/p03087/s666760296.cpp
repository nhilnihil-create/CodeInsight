#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> ans;
    vector<int> cum(100000, 0);
    int cumsum = 0;
    for(int i=1; i<n; i++){  // AC数の累積和
        if(s[i-1]=='A' && s[i]=='C'){
            cumsum++;
        }
        cum[i] = cumsum;
    }
    for(int i=0; i<q; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        ans.push_back(cum[r] - cum[l]);
    }

    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
    return 0;

}