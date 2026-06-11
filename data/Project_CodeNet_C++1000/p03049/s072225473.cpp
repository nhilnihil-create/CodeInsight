#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,n){
        cin>>s[i];
    }
    int ans=0;
    int fB=0,lA=0,fl=0;
    rep(i,n){
        for(int j=0;j<s[i].size()-1;j++){
            if(s[i].substr(j,2)=="AB"){
                ans++;
            }
        }
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A'){
            fl++;
        }
        else if(s[i][0]=='B'){
            fB++;

        }
        else if(s[i][s[i].size()-1]=='A'){
            lA++;
        }
    }
    if(fl==0){
        ans += min(fB,lA);
    }
    else if(fB==0 && lA==0){
        ans += fl-1;
    }
    else if(fB+lA>0){
        ans += fl+min(fB,lA);
    }
    cout<<ans<<endl;
}