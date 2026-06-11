#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    string s;
    cin >> s;
    int ans=700;
    rep(i,3){
        if(s[i]=='o')ans+=100;
    }
    cout << ans << endl;
}
