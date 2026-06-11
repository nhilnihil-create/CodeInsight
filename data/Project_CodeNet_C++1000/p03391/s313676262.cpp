#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int A[200200], B[200200];
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }


    bool flag=true;
    for(int i=0; i<N; i++){
        if(A[i]!=B[i]) flag =false;
    }
    if(flag){cout << 0 << endl; return 0;}

    long long ans=0;
    for(int i=0; i<N; i++){
        ans += A[i];
    }
    int min_num=INT_MAX;
    for(int i=0; i<N; i++){
        if(B[i]<A[i]){
            min_num=min(min_num, B[i]);
        }
    }
    cout << ans-min_num << endl;
}