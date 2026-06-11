#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int t;
    cin >> t;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < t; i++){
        int count = 0;
        vector<string> x(i);
        vector<string> y(t-i);
        //cout << x.size() << " " << y.size() << endl;
        for (int j = 0; j < t; j++){
            if (j < i){x[j] = s[j];}
            else{y[j-i] = s[j];}
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        for (int j = 0; j < (int)x.size(); j++){
            if (find(y.begin(), y.end(), x[j]) != y.end()){count += 1;}
        }
        ans = max(ans, count);
    }

    cout << ans << endl;
    return 0;
}