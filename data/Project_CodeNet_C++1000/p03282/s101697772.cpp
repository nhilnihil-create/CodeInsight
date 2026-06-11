#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    string s; cin >> s;
    ll k; cin >> k;
    int ans=1;
    for(int i=0; i<k; i++){
        if(s.at(i)=='1') continue;
        else{
            ans = s.at(i) - '0';
            break;
        }
    }
    cout << ans << endl;
    return 0;
}