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
int A[222222];

int s[222222];

bool check(int z){
    memset(s,0,sizeof(s));

    stack<int>st;
    for(int i=1;i<N;i++){
        if(i&&A[i-1]<A[i])continue;
        while(st.size()&&st.top()>A[i]){
            s[st.top()]=0;
            st.pop();
        }
        int k=A[i];
        while(true){
            s[k]++;
            if(st.size()==0||st.top()!=k)st.push(k);
            if(s[k]<z)break;
            s[k]=0;
            st.pop();
            k--;
            if(k==0)return false;
        }
    }
    return true;
}

signed main(){
    cin>>N;
    rep(i,N){
        cin>>A[i];
    }

    bool ok=true;
    rep(i,N-1)if(A[i]>=A[i+1])ok=false;

    if(ok){
        cout<<1<<endl;
        return 0;
    }

    rep(i,N)chmin(A[i],222222-1);

    int lb=1,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}