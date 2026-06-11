#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, k;
    cin >> m >> k;

    int pow2m = 1;
    for(int i=0; i<m; i++){
        pow2m *= 2;
    }
    if(k >= pow2m){
        cout << -1 << endl;
        return 0;
    }

    if(m == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    if(m == 1){
        if(k == 0) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        if(k == 1) cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    for(int i=0; i<pow2m; i++){
        if(i != k) ans.push_back(i);
    }
    ans.push_back(k);
    for(int i=pow2m-1; i>=0; i--){
        if(i != k) ans.push_back(i);
    }
    ans.push_back(k);
    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i == ans.size() - 1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}