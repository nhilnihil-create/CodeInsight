#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int N;cin>>N;
    vector<ll> a(N);
    ll S=0;
    REP(i, N){
        cin >> a[i];
        S+=a[i];
        a[i]*=N;
    }
    pair<int,int> ans=make_pair(0,10000);
    REP(i,N){
        if(ans.second>abs(S-a[i])){
            ans=make_pair(i,abs(S-a[i]));
        }
    }
    cout<<ans.first<<endl;
}
