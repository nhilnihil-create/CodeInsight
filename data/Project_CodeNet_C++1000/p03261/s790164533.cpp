#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    map<string,int> kotoba;
    bool ok=true;
    int n;
    cin >> n;
    char old,now;
    rep(i,n){
        string s;
        cin >> s;
        if(kotoba[s]>0){
            ok=false;
        }
        else kotoba[s]++;
        now = s[0];
        if(i!=0){
            if(old != now) ok=false;
        }
        old = s[s.size()-1];
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl; 
}