#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
string  S;

void solve(){
    int K;cin>>K;

    vint lis;
    int cur=0;
    int ans=0;
    int num=0;
    int sum=0;

    vint vec;
    rep(i,N){
        if(S[i]=='D'){
            lis.push_back(i);
            sum-=num;
            vec.push_back(num);
        }
        else if(S[i]=='M'){
            num++;
        }
        else if(S[i]=='C'){
            while(cur<lis.size()&&i-lis[cur]>=K)sum+=vec[cur++];
            ans+=num*(lis.size()-cur)+sum;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin>>N>>S;
    int Q;cin>>Q;
    while(Q--)solve();
}