#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;

vector<ll> a;
void dfs(int keta, string s, int m){
    if(keta==m){
        int seven = 0, five = 0, three = 0;
        rep(i,m){
            if(s[i]=='7') seven++; 
            else if(s[i]=='5') five++; 
            else if(s[i]=='3') three++; 
        }
        if(seven && five && three){
            a.push_back(atoll(s.c_str()));
        }
        return;
    }
    dfs(keta+1,s+'3',m);
    dfs(keta+1,s+'5',m);
    dfs(keta+1,s+'7',m);
}

int main(){
    ll n;
    cin >> n;
    if(n < 356){
        cout << 0 << endl;
        return 0;
    }
    int keta = to_string(n).length();
    for(int i=1; i<=keta+1; i++) dfs(0,"\0",i);
    sort(a.begin(),a.end());
    rep(i,(int)a.size()){
        if(n < a[i]){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}