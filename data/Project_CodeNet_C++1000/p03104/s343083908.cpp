#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
int64_t f(int64_t x){
    if(x%2!=0){//xが奇数
        if((x+1)/2 % 2 == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(x/2 % 2 == 0){
            return 0 ^ x;
        }
        else{
            return 1 ^ x;
        }
    }
}
int main(){
    int64_t a,b;
    cin>>a>>b;
    cout<<(f(a-1)^f(b))<<endl;
}
