#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ans;
    for (int i = 0; i < 100; i++){
        if (a % (i + 1) == 0 && b % (i + 1) == 0){
            ans.push_back(i + 1);
        }
    }
    
    /*for (int i = 0; i < ans.size(); i++){
        cout << ans.at(i) << endl;
    }*/
    reverse(ans.begin(), ans.end());
    
    cout << ans.at(k - 1) << endl;
    
    
    
}