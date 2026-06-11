#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    int H,W,N;cin>>H>>W>>N;
    vector<int> S[W];
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[b].push_back(a);
    }
    
    for(int i=0;i<W;i++){
        sort(all(S[i]));
    }
    
    vector<int> from(W);
    from[0]=0;
    
    for(int j=1;j<W;j++){
        if(S[j].size()==0){
            from[j]=from[j-1]+1;
        }else if(!binary_search(all(S[j]),from[j-1]+1)){
            from[j]=from[j-1]+1;
        }else{
            for(int i=0;i<S[j].size();i++){
                int a=S[j][i];
                if(a>=from[j-1]&&!binary_search(all(S[j]),a+1)){
                    from[j]=a+1;
                    break;
                }
                if(i==S[j].size()-1){
                    if(a==H-1){
                        from[j]=H;
                    }else{
                        from[j]=from[j-1]+1;
                    }
                }
            }
        }
    }
    
    int ans=H;
    
    for(int j=0;j<W;j++){
        for(int i=0;i<S[j].size();i++){
            int a=S[j][i];
            if(from[j]<=a-1) ans=min(ans,a);
        }
    }
    
    cout<<ans<<endl;
    
    
    
}


