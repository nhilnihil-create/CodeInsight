#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s, t;
    cin >> s >> t;
    if(s.size() != t.size()){
        cout << "No\n";
        return 0;
    }
    int n = s.size();
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(s[(i+j) % n] != t[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}