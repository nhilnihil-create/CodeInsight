#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<int> ans;
    ans.push_back(n);

    for(int i=1; i<n; i++){
        if(s[i-1] != s[i]){
            ans.push_back(
                max(i, n-i)
            );
        }
    }
    sort(ans.begin(),ans.end());
    //for(auto a : ans) cout << a << " ";
    //cout << endl;
    cout << ans[0] << endl;
    return 0;
}