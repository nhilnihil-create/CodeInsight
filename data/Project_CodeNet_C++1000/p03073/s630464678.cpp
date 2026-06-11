#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ca=0,cb=0;
    rep(i,n){
        char c = s.at(i);
        if(c == '0'){
            if(i%2==0) ca++;
            else cb++;
        }
        else {
            if(i%2==0) cb++;
            else ca++;
        }
    }
    int res = min(ca,cb);
    cout << res << endl;
    return 0;
}