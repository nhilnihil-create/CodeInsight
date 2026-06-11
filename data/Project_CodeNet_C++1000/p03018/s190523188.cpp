#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    string s;
    cin >> s;
    
    //Aの後ろに"BC"が続いていればAを後に送る
    //Aがいれば合わせて送る
    ll ans = 0;
    ll count = 0;
    bool maeb = false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A'){
            if(maeb)
                count = 0;
            count++;
            maeb = false;
        }
        if(s[i]=='B'){
            if(maeb)
                count = 0;
            maeb = true;
        }
        if(s[i]=='C'){
            if(maeb)
                ans += count;
            else
                count = 0;
            maeb = false;
        }
    }
    cout << ans << endl;
    
    return 0;
}