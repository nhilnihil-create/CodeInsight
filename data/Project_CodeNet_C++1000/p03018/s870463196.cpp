#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    ll check = 0;
    ll ans = 0;
    //cout << s << endl;
    for(ll i = 0; i < s.length(); i++){
        if(s[i]=='A')
            check++;
        else if(s[i]!='A' && i > 0){
            if(s[i]=='B' && s[i+1]=='C'){
                ans+=check;
                i--;
                s.erase(i,2);
            }
            else check = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
