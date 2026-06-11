#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    int k;
    cin >> s >> k;
    set<string> substr;
    int j=1;
    while (1) {
        if (j > fmin(5, s.size())) break;
        for (int i=0; i<s.size()+1-j; i++){
            substr.insert(s.substr(i, j));
        }
        j += 1;
    }
    vector<string> ans(substr.begin(), substr.end());
    cout << ans[k-1] << endl;
    return 0;
}