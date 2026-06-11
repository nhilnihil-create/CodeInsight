#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string s;;
    cin >> s;
    
    if(s[0]!='A'){
        cout << "WA";
        return 0;
    }
    if(s[1]=='C'){
        cout << "WA";
        return 0;
    }
    if(s[s.size()-1]=='C'){
        cout << "WA";
        return 0;
    }
    
    int count = 0;
    rep2(i,1,s.size()){
            if(s[i]=='C')count++;
            else{
                if(isupper(s[i])){
                    cout << "WA";
                    return 0;
                }
            }
            if(count >= 2){
                cout << "WA";
                return 0;
            }
    }
    if(count == 0) cout << "WA";
    else cout << "AC";
    return 0;
}