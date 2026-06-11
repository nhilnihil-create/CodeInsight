#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    int N;cin>>N;
    vector<int> T(13,0);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        T[a]++;
    }
    bool ok=true;
    if(T[0]) ok=false;
    for(int i=0;i<13;i++){
        if(T[i]>2) ok=false;
    }

    if(!ok) cout<<0<<endl;
    else{
        int ans=0;
        for(int bit=0;bit<(1<<12);bit++){
            vector<int> S(24,0);
            S[0]=1;
            for(int i=0;i<13;i++){
                if(T[i]==0) continue;
                if(T[i]==2){
                    S[i]++;
                    S[24-i]++;
                }else{
                    if(bit&(1<<(i-1))){
                        S[i]++;
                    }else S[24-i]++;
                }
            }
            int m=INF,pre=0;
            for(int i=1;i<24;i++){
                if(S[i]){
                    m=min(m,i-pre);
                    pre=i;
                }
            }
            m=min(m,24-pre);
            ans=max(ans,m);

        }

        cout<<ans<<endl;
    }
}
