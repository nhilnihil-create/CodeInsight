#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N,A,B;cin>>N>>A>>B;
    int rep=(N+A-1)/A;
    if(rep<=B&&A+B<=N+1){
        if(A==1){
            for(int i=N;i>=1;i--){
                cout<<i<<endl;
            }
        }else if(B==1){
            for(int i=1;i<=N;i++){
                cout<<i<<endl;
            }
        }else{
            vector<int> S(N);
            int now=0;
            for(int i=rep-1;i>0;i--){
                for(int j=1;j<=A;j++){
                    S[now]=i*A+j-(A-((N-1)%A+1));
                    now++;
                }
            }
            for(int j=1;j<=(N-1)%A+1;j++){
                S[now]=j;
                now++;
            }
            
            int play=B-rep;
            
            for(int i=0;i<play/(A-1);i++){
                reverse(S.begin()+A*i,S.begin()+A*(i+1));
            }
            
            reverse(S.begin()+A*(play/(A-1)+1),S.begin()+A*(play/(A-1)+1)+play%(A-1)+1);
            
            for(int i=0;i<N;i++){
                cout<<S[i]<<endl;
            }
            
        }
    }else cout<<-1<<endl;
    
}


