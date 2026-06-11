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
    for(int i=0; i<s.size()-1; i++){
        if(s[i]=='A')
            count++;
        else if(s[i]=='B' && s[i+1]=='C'){
            ans += count;
            i++;
        }
        else
            count = 0;
    }
    cout << ans << endl;
    
    return 0;
}