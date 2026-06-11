#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    //input
    int n;cin >> n;
    string str; cin >> str;
    vector<int> e(n,0);
    vector<int> w(n,0);
    vector<int> change(n,0);

    //compute
    int ans = 0;
    e[0] = bool(str.at(0) == 'E');
    w[0] = bool(str.at(0) == 'W');

    for(int i = 1; i < n; i++){
            if(str.at(i) == 'E'){
                e[i] = e[i - 1] + 1;
                w[i] = w[i - 1];
            }else{
                w[i] = w[i - 1] + 1;
                e[i] = e[i - 1];                
            }
    }

    for(int i = 0; i < n; i++) {
        if(str.at(i) == 'E'){
            change[i] = w[i] + e[n - 1] - e[i];
        }else{
            change[i] = w[i] - 1 + e[n - 1] - e[i];
        }
    }

    sort(change.begin(),change.end());

    ans = change[0];

    //output
    cout << ans << endl;

}
