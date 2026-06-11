#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    char ini = '1';
    int len = 0;
    rep(i,(int)s.size()){
        if(s[i]=='1'){
            len++;
        }
        else{
            ini = s[i];
            break;
        }
    }
    if(k <= len){
        cout << 1 << endl;
    }
    else{
        cout << ini << endl;
    }




    return 0;
}