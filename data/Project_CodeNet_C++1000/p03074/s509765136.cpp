#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
//コンビネーションを10^9+7で割った余りを求める
const int MOD=1000000007;
int main(){
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
   //FILE *fp;
   //fp = fopen("~/Downloads/testcase_12.txt","r")
    vector<int> zo;
    int a=1;
    if(n==1){
        zo.push_back(a);
    }
    if(s[0]=='0'){
        zo.push_back(0);
    }
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            a++;
        }
        else{
            zo.push_back(a);
            a=1;
        }
        if(i==n-1){
            zo.push_back(a);
        }
    }
    int l=zo.size();
    vector<int> sum(l+1,0);
    for(int i=1;i<=l;i++){
        sum[i] = sum[i-1] + zo[i-1];
    }
    /*
    rep(i,l){
        //cout<<sum[i]<<" ";
        cout<<zo[i]<<endl;
    }
    cout<<endl;
    */
    int ans=0;

    for(int i=0;i<l+1;i+=2){
        int tmp = sum[min(l,i+2*k+1)]-sum[i];
        //cout<<tmp<<endl;
        ans = max(ans,tmp);
    }
    cout<<ans<<endl;
}