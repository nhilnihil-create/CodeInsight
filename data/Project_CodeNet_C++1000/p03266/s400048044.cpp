#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;

int main(){
    ll n,k;cin>>n>>k;
    ll a,b,c,ans=0;
    vector<bool> visit(k,false);


    ll spare;//aに対しての、b,cのあまり(条件を満たすようにあまりで探索)
    for(a=1;a<=n;a++){
        if(a%k>=0){spare=k-(a%k);}//aとペアになれる数のあまりを求める->個数も求める
        else{spare=-(a%k);}

        if(!(visit[spare]) && (2*a)%k==0){ans+=(((n-spare)/k+1)*((n-spare)/k+1)*((n-spare)/k+1));}
        //!(visit[spare])は重複して数えるのを防ぐ
        //(2*a)%k==0は、上では(a,b) (a,c)の和しか判定できていないので(b,c)の判定を行っている(連立方程式を立てれば分かる)
        visit[spare]=true;
    }

    cout<<ans<<endl;
    return 0;
}