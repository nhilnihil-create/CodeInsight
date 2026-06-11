#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    int N,K,Q;cin>>N>>K>>Q;
    vector<int> A(N),B(N-K+1);//B[i]はi~i+K-1の最小値
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    deque<int> deq(N);
    int s=0,t=0;
    for(int i=0;i<N;i++){
        while(s<t&&A[deq[t-1]]>=A[i]) t--;
        deq[t]=i;
        t++;
        
        if(i-K+1>=0){
            B[i-K+1]=A[deq[s]];
            if(deq[s]==i-K+1) s++;
        }
    }
    
    int ans=INF;
    
    if(Q==1) cout<<0<<endl;
    else{
        for(int i=0;i<N;i++){
            bool flag=false;
            //if(N-i<Q) continue;
            for(int j=max(0,i-K+1);j<=i;j++){
                if(B[j]==A[i]){
                    flag=true;
                    break;
                }
            }
            if(!flag) continue;
            
            vector<int> S[N],T={A[i]};
            int start=0,cnt=0;
            
            for(int j=0;j<N;j++){
                if(i==j) continue;
                
                if(A[j]<A[i]){
                    start=j+1;
                }else{
                    S[start].push_back(A[j]);
                }
            }
            
            for(int j=0;j<N;j++){
                if(S[j].size()>=K) cnt+=(S[j].size()-K+1);
            }
            
            if(cnt<Q-1) continue;
            
            for(int j=0;j<N;j++){
                if(S[j].size()>=K){
                    sort(all(S[j]));
                    for(int k=0;k<min(int(S[j].size()-K+1),Q-1);k++){
                        T.push_back(S[j][k]);
                    }
                }
            }
            
            sort(all(T));
            
            ans=min(ans,T[Q-1]-T[0]);
        }
        
        cout<<ans<<endl;
    }
    
}
