#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
   // 制約見て！！！デカかったらlong longにすること！

    string s;
    int w;

    cin >> s >> w;

    string ans;
    int i = 0,slen=s.size();
    while(true){
        if(i>=slen){
            break;
        }
        ans += s[i];
        i+=w;
    }

    cout<<ans<<endl;
}
