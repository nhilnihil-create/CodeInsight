#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    int ans;
    if(b>=c){//解毒入りおいしいがいっぱい
        ans = b+c;
    }
    else if(a+b>=c){//解毒しきれる
        ans = c+b;
    }
    else{
        ans = 2*b;
        c -= b;
        ans += a+1;
    }
    cout <<ans<<endl;
}