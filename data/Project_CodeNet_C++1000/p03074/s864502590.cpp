#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> sum;
ll i;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}
ll query(ll i,ll j,vector<ll> &s){//区間[i,j]の和
    return s[j]-s[i];
}


int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    vector<ll> a;

    if(n==1){cout<<"1"<<endl;return 0;}//例外処理

    vector<ll> Nums;//1 0の塊の大きさを記録する配列
    int now=1;//今見ている数
    int cnt=0;//nowがいくつ並んでいるか
    for(i=0;i<n;i++){
        if(s[i]==(char)('0'+now)){cnt++;}
        else{
            Nums.push_back(cnt);//最初に1がなければ0が追加される
            now=1-now;//0 1の交換
            cnt=1;//新しいのをカウント
        }
    }
    if(cnt!=0){Nums.push_back(cnt);}

    //0で終わっていたらたす
    if(Nums.size()%2==0){Nums.push_back(0);}
    //1で始まり1で終わる

    pre_process(Nums,sum);//累積和の作成

    ll add=2*k+1;
    ll ans=-1;
    for(i=1;i<=sum.size()-add;i+=2){
        if(i+add-1>sum.size()){cout<<n<<endl;return 0;}//例外処理
        ans=max(ans,query(i-1,i+add-1,sum));//できる限り多くひっくり返したときの最大人数
    }

    cout<<ans<<endl;
    return 0;
}