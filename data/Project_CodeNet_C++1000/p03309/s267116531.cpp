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
    vector<int64_t> a(n);
    int64_t min = 10000000000;
    int64_t max = 0;
    int64_t sum=0;
    rep(i,n){
        cin>>a[i];
        a[i] -= (i+1);
    }
    all(a);
    int64_t med;
    int64_t ans = 0;
    if(n%2!=0){
        med = a[n/2];
        rep(i,n){
            ans += abs(a[i]-med);
        }
    }
    else{
        int64_t M = 10000000000000000;
        for(int64_t med = a[n/2-1];med<=a[n/2];med++){
            int64_t sad = 0;
            rep(i,n){
                sad += abs(a[i]-med);
            }
            if(sad<M){
                M = sad;
            }
        }   
        ans = M;
    }
    cout<<ans<<endl;
}