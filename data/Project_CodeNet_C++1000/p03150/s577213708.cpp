#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    string t = "keyence";
    int n = s.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n; j++){
            string tmp = s;
            tmp.erase(tmp.begin()+i,tmp.begin()+j);
            if(t == tmp){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}