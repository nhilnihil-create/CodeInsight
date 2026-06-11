#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> w(n);
    set<string> chk;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        int chk_size0 = chk.size();
        chk.insert(w[i]);
        int chk_size1 = chk.size();
        if(chk_size0==chk_size1) {
            cout << "No" << endl;
            return 0;
        } else if(i > 0) {
            if(w[i-1].back()==w[i].front()) {
                continue;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}