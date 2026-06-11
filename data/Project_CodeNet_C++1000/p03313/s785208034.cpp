#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N;cin>>N;
    int M=(1<<N);
    vector<int> A(M),m1(M,0),m2(M,0);
    for(int i=0;i<M;i++){
        cin>>A[i];
    }
    
    for(int i=1;i<M;i++){
        
        for(int j=i;j>0;j=(j-1)&i){
            if(A[j]>m1[i]){
                m2[i]=m1[i];
                m1[i]=A[j];
            }else if(A[j]>m2[i]){
                m2[i]=A[j];
            }
        }
        
        if(A[0]>m1[i]){
            m2[i]=m1[i];
            m1[i]=A[0];
        }else if(A[0]>m2[i]){
            m2[i]=A[0];
        }
    }
    
    int now=0;
    for(int i=1;i<M;i++){
        now=max(now,m1[i]+m2[i]);
        cout<<now<<endl;
    }
    
}

