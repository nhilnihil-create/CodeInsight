/*
      author  : nishi5451
      created : 14.08.2020 16:40:26
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    rep(i,a+b+1){
        if(i==a){
            if(s[i]!='-'){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            if(s[i]>='0' && s[i]<='9')
                continue;
            else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
