#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    string key="keyence";
    string s; cin >> s;

    
    // 前半一致数
    int mae=0;
    while(s[mae]==key[mae]){
        mae++;
    }

    // 後半一致
    int usiro=0;
    while(s[s.size()-1 - usiro] == key[key.size() -1 -usiro]){
        usiro++;
    }


    if(mae + usiro >=key.size()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
