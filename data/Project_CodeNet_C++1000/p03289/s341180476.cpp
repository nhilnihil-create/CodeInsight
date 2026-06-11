#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s;   cin >> s;

    bool ans(true);
    int count(0);
    if(s[0]!='A'){
        ans = false;
    }

    for(int i=1;i<=s.size()-1;i++){
        if(isupper(s[i])){
            if(s[i]=='C' && i>=2 && i<=s.size()-2){
                count++; 
            }else{
                ans = false;
            }
        }
    }

    if(ans){
        if(count==1){
            cout << "AC" << endl;
        }else{
            cout << "WA" << endl;
        }
    }else{
        cout << "WA" << endl;
    }

    return 0;
}