#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    string s;
    cin >> s;
    int ans10=0, ans01=0;
    
    string flg="mae";
    for(int i=0; i<s.size(); i++){
        if(flg=="mae"){
            if(s[i]=='0'){
                ans10++;
            }else if(s[i]=='1'){
                ans01++;
            }
            flg="usiro";
            continue;
        }
        
        if(flg=="usiro"){
            if(s[i]=='0'){
                ans01++;
            }else if(s[i]=='1'){
                ans10++;
            }
            flg="mae";
            continue;
        }
    }
    
    int min_ans=min(ans10, ans01);
    cout << min_ans << endl;
    
    //cout << s[1] << endl;
}
