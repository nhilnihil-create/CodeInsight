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

signed main(){
    int N,A,B;
    cin>>N>>A>>B;

    vint ans;
    if(A==1){
        if(B!=N){
            cout<<-1<<endl;
            return 0;
        }
        rep(i,N)ans.pb(-i);
    }
    else if(B==1){
        if(A!=N){
            cout<<-1<<endl;
            return 0;
        }
        rep(i,N)ans.pb(i);
    }
    else{
        if(A+B-1>N||A*B<N){
            cout<<-1<<endl;
            return 0;
        }
        int r=N-A;
        for(int i=0;i<A;i++){
            ans.pb(i*1000000);
            for(int j=0;r&&j+1<B;j++){
                r--;
                ans.pb(ans.back()-1);
            }
        }
    }


    vint latte;
    rep(i,N)latte.pb(ans[i]);
    sort(all(latte));
    rep(i,N){
        if(i)cout<<" ";
        cout<<lower_bound(all(latte),ans[i])-latte.begin()+1;
    }cout<<endl;
    return 0;
}
