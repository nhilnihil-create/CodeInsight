#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;

    long long cnt =0;
    long long ans = 0;
    int flg =false;
    for(int i=0; i<s.length(); i++){
        if(s.at(i)=='B'){
            cnt++;
        }else{
            ans += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}