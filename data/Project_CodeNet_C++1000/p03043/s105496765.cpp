#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n,k;
    cin>>n>>k;
    int a=1;//2^a<=kとなるようにする
    //はじめに1が出たときにa回表が出ればk以上になる
    while((1<<a)<k) a++;
    int ans=0;//1が出た時の確立を単位として数える
    double q=n*(1<<a);//1が出て勝つ確率の逆数
    int temp=1;//初めにでた目
    int b=0;//a+bが一定になるようにする
    //a回で初めてk以上になるように
    while(temp<=n){
        if((temp<<(a-1))>=k){
            a--;
            b++;
        }
        //cout<<temp<<" "<<(1<<b)<<endl;
        ans+=(1<<b);
        temp++;
    }
    //cout<<ans<<" "<<q<<endl;
    double p=double(ans/q);
    //cout<<p<<endl;
    printf("%.15f\n",p);
    return 0;
}