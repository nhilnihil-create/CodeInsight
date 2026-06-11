#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

int main(){
    int A,B,K;cin>>A>>B>>K;
    REP(i,K){
        if(i&1){
            if(B&1) B--;
            A+=B/2;
            B/=2;
        }
        else{
            if(A&1) A--;
            B+=A/2;
            A/=2;
        }
    }
    cout<<A<<" "<<B<<endl;
}
