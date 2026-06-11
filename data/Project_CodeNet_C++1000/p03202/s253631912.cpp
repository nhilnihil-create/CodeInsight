#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=51,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    int left=0,right=INF;
    
    while(right-left>1){
        int mid=(left+right)/2;
        bool ok=true;
        
        vector<pair<int,int>> S;
        S.push_back({1,A[0]});
        for(int i=1;i<N;i++){
            if(A[i-1]<A[i]){
                auto p=S.back();
                if(p.first==1){
                    S.pop_back();
                    S.push_back({1,p.second+A[i]-A[i-1]});
                }else S.push_back({1,A[i]-A[i-1]});
            }else{
                int sum=A[i-1];
                while(S.size()&&sum-S.back().second>=A[i]){
                    sum-=S.back().second;
                    S.pop_back();
                }
                
                while(S.size()&&S.back().first==mid){
                    sum-=S.back().second;
                    S.pop_back();
                }
                
                if(S.size()==0){
                    ok=false;
                    break;
                }
                
                if(sum>A[i]){
                    auto p=S.back();
                    sum-=S.back().second;
                    S.pop_back();
                    
                    if(A[i]-1-sum>0){
                        S.push_back({p.first,A[i]-1-sum});
                        sum+=A[i]-1-sum;
                    }
                    
                    S.push_back({p.first+1,1});
                    sum++;
                    
                    if(sum<A[i]) S.push_back({1,A[i]-sum});
                    
                    sum=A[i];
                }else{
                    auto p=S.back();
                    sum-=S.back().second;
                    S.pop_back();
                    
                    if(p.second>1){
                        S.push_back({p.first,p.second-1});
                        sum+=p.second-1;
                    }
                    
                    S.push_back({p.first+1,1});
                    sum++;
                    
                    if(sum<A[i]) S.push_back({1,A[i]-sum});
                }
                
            }
        }
        
        if(ok) right=mid;
        else left=mid;
    }
    
    cout<<right<<endl;
}

