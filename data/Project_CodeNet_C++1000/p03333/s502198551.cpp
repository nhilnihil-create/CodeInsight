#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=51;
const ll INF=1LL<<55;

int main(){
    
    int N;cin>>N;
    vector<pair<ll,int>> L(N),R(N);
    vector<int> used(N);
    for(int i=0;i<N;i++){
        cin>>L[i].first>>R[i].first;
        L[i].second=i;
        R[i].second=i;
    }
    
    sort(all(L));
    sort(all(R));
    reverse(all(L));
    
    ll left=0,right=0,sum1=0,sum2=0,now=0;
    
    for(int k=0;k<N;k++){
        while(left<N&&used[L[left].second]){
            left++;
        }
        if(left==N) break;
        if(L[left].first-now<=0) break;
        sum1+=(L[left].first-now);
        now=L[left].first;
        used[L[left].second]=1;
        
        while(right<N&&used[R[right].second]){
            right++;
        }
        if(right==N) break;
        if(now-R[right].first<=0) break;
        sum1+=(now-R[right].first);
        now=R[right].first;
        used[R[right].second]=1;
    }
    
    sum1+=abs(now);
    
    left=0;right=0;now=0;
    
    for(int i=0;i<N;i++){
        used[i]=0;
    }
    
    for(int k=0;k<N;k++){
        while(right<N&&used[R[right].second]){
            right++;
        }
        if(right==N) break;
        if(now-R[right].first<=0) break;
        sum2+=(now-R[right].first);
        now=R[right].first;
        used[R[right].second]=1;
        
        while(left<N&&used[L[left].second]){
            left++;
        }
        if(left==N) break;
        if(L[left].first-now<=0) break;
        sum2+=(L[left].first-now);
        now=L[left].first;
        used[L[left].second]=1;
    }
    
    sum2+=abs(now);
    
    //cout<<sum1<<" "<<sum2<<endl;
    cout<<max(sum1,sum2)<<endl;
    
}

