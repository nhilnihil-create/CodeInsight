#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    bool flag = true;
    string n; cin >> n;

    for(int i = 1; i < n.size(); i++){
        if(n[i] != '9'){ flag = false; }
    }
    if(flag){
        cout << 9 * (n.size() - 1) + (n[0] - '0') << endl;
        return 0;
    }

    if(n[0] > '1'){
        cout << 9 * (n.size() - 1) + (n[0] - '0') - 1 << endl;  
    }else{
        cout << 9 * (n.size() - 1) << endl;
    }
}