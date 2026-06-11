#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int64_t a,b,c,k;
    cin >> a>>b>>c>>k;
    if(abs(a-b)>pow(10,18)){
        cout<<"Unfair"<<endl;
    }
    else{
        if(k%2==0){
            cout<<a-b<<endl;
        }
        else{
            cout<<b-a<<endl;
        }
    }
}