#include "./bits/stdc++.h"
using namespace std;
int N,M;

int main(){
    cin>>N>>M;
    int m[M];
    int d[M-1];
    for(int i=0;i<M;i++){
        cin >> m[i];
    }

    if(N>=M){
        cout << 0 << endl;
    }else{
        sort(m,m+M);
        for(int i=0;i<M-1;i++){
            d[i]=abs(m[i+1]-m[i]);
        }
        sort(d,d+M-1);
        int sum = 0;        
        for(int i=0;i<N-1;i++){
            sum+=d[M-2-i];
        }        
        cout << abs(m[0]-m[M-1])-sum << endl;
    }
    return 0;
}