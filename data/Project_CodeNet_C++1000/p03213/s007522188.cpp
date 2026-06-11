#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<ll,ll>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;
//あとでやる https://atcoder.jp/contests/abc114/tasks/abc114_d
int main(){
    int N;
    cin>>N;
    vi prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    //for(int i=0;i<prime.size();i++)cout<<prime[i]<<" ";
    //cout<<endl;
    vi pow_count(prime.size(),0);
    for(int j=1;j<=N;j++){
        for(int i=0;i<prime.size();i++){
            int x=j;
            while(x%prime[i]==0){
                x/=prime[i];
                pow_count[i]++;
            }
        }
    }
    //for(int i=0;i<prime.size();i++)cout<<pow_count[i]<<" ";
    //cout<<endl;
    int ans=0;
    for(int i=0;i<prime.size();i++){
        if(pow_count[i]<2)continue;
        for(int j=0;j<prime.size();j++){
            if(i==j)continue;
            if(pow_count[j]<4)continue;
            for(int k=j+1;k<prime.size();k++){
                if(i==k)continue;
                if(pow_count[k]<4)continue;
                ans++;
            }
        }
    }
    for(int i=0;i<prime.size();i++){
        if(pow_count[i]<24)continue;
        for(int j=0;j<prime.size();j++){
            if(i==j)continue;
            if(pow_count[j]<2)continue;
            ans++;
        }
    }
    for(int i=0;i<prime.size();i++){
        if(pow_count[i]<14)continue;
        for(int j=0;j<prime.size();j++){
            if(i==j)continue;
            if(pow_count[j]<4)continue;
            ans++;
        }
    }
    if(pow_count[0]>=74)ans++;
    cout<<ans<<endl;
}