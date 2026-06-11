#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL N;
    cin >> N;
    vector<LL>  a(N+1);
    LL M = -1000001;
    LL m = 1000001;
    LL Mid = 0;
    LL mid = 0;
    for(int i = 1;i <= N;i++){
        cin >> a[i];
        if(M < a[i]){
            M = a[i];
            Mid = i;
        }
        if(m > a[i]){
            m = a[i];
            mid = i;
        }
    }
    cout << 2*N << endl;
    if(m > 0 || abs(M) >= abs(m)){
        a[1] += M*2;
        cout << Mid << " " << 1 << endl;
        cout << Mid << " " << 1 << endl;
        for(int i = 2;i <= N;i++){
            a[i] += a[1]+a[i-1];
            cout << 1 << " " << i << endl;
            cout << i-1 << " " << i << endl;
        }
    }else{
        a[N] += m*2;
        cout << mid << " " << N << endl;
        cout << mid << " " << N << endl;
        for(int i = N-1;i >= 1;i--){
            a[i] += a[N]+a[i+1];
            cout << N << " " << i << endl;
            cout << i+1 << " " << i << endl;
        }
    }
}