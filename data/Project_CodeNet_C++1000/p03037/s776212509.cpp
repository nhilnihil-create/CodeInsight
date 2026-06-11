#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N,M;
    cin >> N >> M;
    int L[M],R[M];
    for(int i=0;i<M;i++)cin >> L[i] >> R[i];
    int AL=L[0],AR=R[0];
    for(int i=1;i<M;i++){
        if(L[i]>=AL){
            AL=L[i];
        }
        if(R[i]<AR){
            AR=R[i];
        }
    }
    if(AR-AL>=0){
        cout << AR - AL +1 << endl;
    }else{
        cout << 0 << endl;
    }
    
}