#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    ll N,P,end;
    cin >> N >> P;
    ll B[1000000];
    ll A[1000000];
    Fill(A,(ll)0);
    Fill(B,(ll)0);
    end = 1;
    int C = 0;
    for(ll i = 2;i*i <= P;i++){
        if(P % i == 0){
            while(P % i == 0){
                A[C]++;
                P /= i;
            }
            B[C] = i;
            C++;
        }
    }
    if(P != 1){
        B[C] = P;
        A[C] = 1;
    }
    ll ans = 1;
    int ts;
    for(ll i = 0;i <= C;i++){
        ts = A[i] / N;
        if(ts != 0)
            ans *= pow(B[i],ts);
    }
        
    cout << ans << "\n";
    return 0;
}