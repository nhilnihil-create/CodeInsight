#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "keyence";
    bool flag = false;
    rep(i,s.size()){
        rep(j,s.size()){
            string t = s;
            t.erase(i,j);
            if(ans == t){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}