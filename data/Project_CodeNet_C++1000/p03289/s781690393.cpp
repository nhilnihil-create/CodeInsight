/*
      author  : nishi5451
      created : 14.08.2020 19:39:42
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,int(s.size())){
        if(i==0){
            if(s[i]!='A'){
                cout << "WA" << endl;
                return 0;
            }
        }
        else if(i==1 || i==s.size()-1){
            if(!(s[i]>='a' && s[i]<='z')){
                cout << "WA" << endl;
                return 0;
            }
        }
        else{
            if( !(s[i]>='a' && s[i]<='z') ){
                if(s[i]!='C'){
                    cout << "WA" << endl;
                    return 0;
                }
                cnt++;
            }
        }
    }
    if(cnt!=1) cout << "WA" << endl;
    else cout << "AC" << endl;
    return 0;
}