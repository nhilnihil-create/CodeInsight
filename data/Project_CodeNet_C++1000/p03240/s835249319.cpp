#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007

int main(){
    int64_t n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    rep(i,n){
        cin >> x[i]>>y[i]>>h[i];
    }
    int H;
    rep(cx,101){
        rep(cy,101){
            set<int> s;
            rep(i,n){
                //ここでHがn点のデータに対して等しければそこがcx,cy;
                if(h[i]>0){
                H = h[i]+abs(x[i]-cx)+abs(y[i]-cy);
                s.insert(H);
                }
                else{
                    //h[i]==0ならこの条件を満たしてないといけない
                    //H<=abs(x[i]-cx)+abs(y[i]-cy)
                }
            }
            if(s.size()==1){
                bool ok=true;
                rep(i,n){
                    if(h[i]==0 && H>abs(x[i]-cx)+abs(y[i]-cy)){
                        ok=false;
                    }
                }
                if(ok)cout<<cx<<" "<<cy<<" "<<H<<endl;
            }
        }
    }
    
}