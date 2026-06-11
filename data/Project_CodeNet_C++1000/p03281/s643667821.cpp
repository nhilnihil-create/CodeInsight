
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    int tmp;
    int count=0;
    int ans=0;
    for(int i=1;i<=N;i++){
        tmp=i;
        if(tmp%2==0){//偶数かどうか確認
            continue;
        }
        for(int j=1;j<=N;j+=2){//正の約数の個数を確認(奇数で割っていく)
            if(tmp%j==0){
                count++;
            }
        }
        if(count==8){
            ans++;
        }
        count=0;
    }
    cout<<ans<<endl;
}