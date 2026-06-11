#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    vector<int> ans(n);
    while(b.size() != 0){
        bool flag = false;
        for(int i=b.size()-1; i>=0; i--){
            if(b[i] == i+1){
                ans.push_back(b[i]);
                b.erase(b.begin() + i);
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}