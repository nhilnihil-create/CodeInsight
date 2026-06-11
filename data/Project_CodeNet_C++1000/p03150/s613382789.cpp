#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            string t = s.substr(0, j) + s.substr(j+i, n-1);
            //cout << t << endl;
            if(t == "keyence"){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}