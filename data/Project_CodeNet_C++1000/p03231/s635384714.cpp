#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int64_t n,m;
    cin >> n>> m;
    string s,t;
    cin >> s>>t;
    int64_t l = n*m/__gcd(n,m);
    if(s[0]!=t[0]){
        cout<<-1<<endl;
    }
    else{
        if(l==m*n){
        cout<<l<<endl;
        }
        else{
            int i=0;
            while(i*l/m<n){
                if(s[i*l/m]!=t[i*l/n]){
                    cout<<-1<<endl;
                    return 0;
                }
                i++;
            }
            cout<<l<<endl;
        }
    }
}