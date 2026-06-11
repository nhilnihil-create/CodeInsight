
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    string ans = "Yes";
    rep(i,s.size()){
        if(s[i]=='-' && i!=a){
            ans="No";
        }
        if(s[a]!='-'){
            ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}