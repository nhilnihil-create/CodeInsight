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

int calc(int X,int B){
    int lb=0,ub=X+114;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        int tmp=X/(B+mid);
        if(mid<=tmp)lb=mid;
        else ub=mid;
    }

    return lb;
}

signed main(){


    int Q;cin>>Q;


    while(Q--){
        int A,B;
        cin>>A>>B;
        if(A>B)swap(A,B);
        int X=A*B;

        int lb=0,ub=1001001001;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(mid*mid<=X-1)lb=mid;
            else ub=mid;
        }
        int a=1001001001;
        for(int i=-1000;i<=1000;i++){
            int x=lb+i;
            if(x<=A)continue;
            if((X-1)<x)continue;
            chmin(a,x-A+(X-1)/x-1);
        }
       if(a==1001001001)a=0;
        int b=A-1;


        int ans=a+b;
        cout<<ans<<endl;
    }
    return 0;
}
