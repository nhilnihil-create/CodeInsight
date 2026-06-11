#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N,KK;
    cin>>N>>KK;
    vector<long long> vec(N);
    for(long long i=0;i<N;i++){
        cin>>vec.at(i);
    }
    long long ans=-1000000000;
    vector<long long> check(0);
    vector<long long> memo;
    vector<long long> memomemo(0);
    for(long long K=0;K<=KK;K++){
    for(long long i=0;i<=K;i++){
        check=memomemo;
        if(i%2!=K%2 || i>N){
            continue;
        }
        for(long long L=0;L<=N;L++){
            if(L>0)check.push_back(vec.at(L-1));
            memo=check;
            for(long long R=0;R<=N;R++){
                long long x=0;
                if(R>0)check.push_back(vec.at(N-R));
                if(L+R>N || L+R<i || L+R>K || L+R+L+R-i>K){
                    continue;
                }
                //L+R-iが返す量
                //iが残る量
                sort(check.begin(),check.end());
                reverse(check.begin(),check.end());
                for(long long j=0;j<i;j++){
                    x+=check.at(j);
                    //cout<<L<<" "<<R<<" "<<check.at(j)<<endl;
                }
                ans=max(ans,x);
            }
            check=memo;
        }
    }
    }
    cout<<ans<<endl;
}