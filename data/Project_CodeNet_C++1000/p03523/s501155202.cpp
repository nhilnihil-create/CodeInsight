#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    vector<string> a={"KIH","B","R"};
    int ok=0;
    for (int mask=0;mask<(1<<4);++mask){
        string check="";
        for (int i=0;i<4;++i){
            if (mask&1<<i) check+='A';
            if (i<3) check+=a[i];
        }
        if (S==check) ok=1;
    }
    cout << (ok?"YES":"NO") << '\n';
}