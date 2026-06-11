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
int main(){
    int64_t n;
    int k;
    cin>>n>>k;
    int64_t ans=0;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(int b=k+1;b<=n;b++){
        int p;//aをbで割ったあまりの数列の個数
        p = n/b;
        //1この塊のなかに、条件に合うのはb-k
        int amari = n%b;
        //切れ端amari個の中で条件に合うのはamari-k+1個
        //amari = 5 => 1,2,3,4,5  k = 3だったらその中の3,4,5 が条件にあう
        //amari=3 -> 1,2,3 k=5だったら、amari-k+1が負になるので、その場合はつまり0
        ans += p*(b-k) + max(amari-k+1,0);
    }
    cout<<ans<<endl;
}