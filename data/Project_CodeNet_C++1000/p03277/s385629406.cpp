#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int bit[MAX+1],M;

//1-indexed

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//sからtの和=sum(t)-sum(s-1)

void add(int i,int x){
    while(i<=M){
        bit[i]+=x;
        i+=i&-i;
    }
}


int main(){
    
    int N;cin>>N;M=N+1;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    int left=0,right=INF;
    
    while(right-left>1){
        int mid=(left+right)/2;
        vector<int> B(N+1,0);
        for(int i=1;i<=N;i++){
            if(A[i-1]>=mid) B[i]=1;
            else B[i]=-1;
            B[i]+=B[i-1];
        }
        vector<int> id(N+1);
        iota(id.begin(),id.end(),0);
        sort(id.begin(),id.end(),[&](int i,int j){
            if(B[i]!=B[j]) return B[i] > B[j];
            return i>j;
        });
        
        for(int i=0;i<=MAX;i++){
            bit[i]=0;
        }
        
        ll cnt=0;
        
        for(int i=0;i<N+1;i++){
            cnt+=sum(N+1)-sum(id[i]+1);
            add(id[i]+1,1);
        }
        
        if(cnt>=(ll(N+1)*ll(N)/2+1)/2) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}

