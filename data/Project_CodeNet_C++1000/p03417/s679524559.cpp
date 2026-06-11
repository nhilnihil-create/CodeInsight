#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int64_t n,m;
    cin>>n>>m;
    if(n>=3&&m>=3){
        cout<<(n-2)*(m-2)<<endl;
    }
    else if(n==2||m==2){
        cout<<0<<endl;
    }
    else if(n+m>=3){//1,2以上
        //n<=mに変える
        if(n>m){
            int tmp = n;
            n = m;
            m = tmp;
        }
        cout<< m-2<<endl;
    }
    else if(n==1&&m==1){
        cout<<1<<endl;
    }
}