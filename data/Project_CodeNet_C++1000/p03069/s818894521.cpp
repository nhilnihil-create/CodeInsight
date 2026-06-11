#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> w(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='.'){
            w[i] = w[i-1] + 1;
            b[i] = b[i-1];
        }
        else{
            w[i] = w[i-1];
            b[i] = b[i-1] + 1;
        }
    } 
    /*
    rep(i,n+1){
        cout<<w[i]<<" ";
    }
    cout<<endl;
    rep(i,n+1){
        cout<<b[i]<<" ";
    }
    */
    int Min=10000000;
    rep(i,n+1){
        int change = b[i] + w[n]-w[i];
        if(change<Min){
            Min = change;
        }
    }
    cout<<Min<<endl;
}