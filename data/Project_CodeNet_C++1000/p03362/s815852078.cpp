#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

vector<bool> sieve(int MAX_A){
    vector<bool> p(MAX_A+1,true);
    p[0]=p[1]=false;
    REP(i,MAX_A+1) if(p[i]){
        for(int j=2*i;j<=MAX_A;j+=i){
            p[j]=false;
        }
    }
    return p;
}

int main(){
    int N;cin>>N;
    vector<bool> p=sieve(55555);
    vector<int> ans;
    REP(i,55556){
        if(ans.size()==N){
            REP(j,N) cout<<ans[j]<<" \n"[j+1==N];
            return 0;
        }
        if(i%5==1&&p[i]){
            ans.push_back(i);
        }
    }
}