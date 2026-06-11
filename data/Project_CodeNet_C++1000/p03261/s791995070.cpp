#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string ans="Yes";
    vector<string> w(n);
    for(int i=0; i<n; i++){
        cin >> w.at(i);
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(w.at(i)==w.at(j)) ans="No";
        }
        if(w.at(i).front()!=w.at(i-1).back()) ans="No";
//        cout << ans << endl;
    }
    cout << ans << endl;
}