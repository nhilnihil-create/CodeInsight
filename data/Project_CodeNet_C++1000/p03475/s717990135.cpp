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
    int n;
    cin>>n;
    vector<int> c(n-1),s(n-1),f(n-1);
    rep(i,n-1){
        cin>>c[i]>>s[i]>>f[i];
    }
    vector<int> arrive(n,0);
    //int arrive=s[0];
    rep(i,n-1){
        arrive[i] = s[i];
        for(int j=i;j<n-1;j++){
            arrive[i] += c[j];
            if(i==0){
            //cout<<"arrived at station"<<j+1<<" in"<<arrive[i]<<endl;
            }
            if(j==n-2){
                break;
            }
            //待ち時間がある場合は加算
            if(arrive[i]<s[j+1]){
                arrive[i]=s[j+1];
            }
            if((arrive[i]-s[j+1])%f[j+1]!=0){
                arrive[i] += f[j+1] - (arrive[i]-s[j+1])%f[j+1]; 
            }
        }
        cout<<arrive[i]<<endl;
    }
    cout<<0<<endl;
}