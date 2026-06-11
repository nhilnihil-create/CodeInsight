#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
#define mp(a,b) make_pair(a,b)
int main(){
    int64_t n;
    cin>>n;
    int64_t ans=0;
    set<int64_t> s;
    //O(√N)で約数列挙
    s.insert(1);
    s.insert(n);
    for(int64_t i=2;i*i<=n;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    //m = N/x-1;
    for(auto c:s){
        int64_t x = c;
        int64_t m = n/c-1;
        if(m>x) ans += m;
        //cout<<"x:"<<c<<" m:"<<n/c-1<<endl;
    }
    cout<<ans<<endl;
}