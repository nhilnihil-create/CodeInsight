// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    set<string> s;
    s.insert(str);
    --n;
    while(n--){
        string temp;
        cin>>temp;
        int len = str.length();
        --len;
        if(s.count(temp) || temp[0] != str[len]){
            cout<<"No";
            return ;
        }
        s.insert(temp);

        str = temp;
    }
    cout<<"Yes";
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}