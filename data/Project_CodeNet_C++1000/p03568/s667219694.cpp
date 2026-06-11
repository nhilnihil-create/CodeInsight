#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int g=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==0){
            g++;
        }
    }
    int ans = pow(3,n);
    ans = ans - pow(2,g);
    cout<<ans<<endl;
}