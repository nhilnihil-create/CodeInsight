#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

long gcd(long A, long B){
    long v0 = A, v1 = B, v2 = A % B;
    while(v2 != 0){
        v0 = v1;
        v1 = v2;
        v2 = v0 % v1;
    }
    return v1;
}

long lcm(long A, long B){
    return A/gcd(A, B)*B;
}

int main() {
    long N, M;
    cin>>N>>M;
    string S, T;
    cin>>S>>T;
    if(N<M){
        swap(N, M);
        swap(S, T);
    }
    long L = lcm(N, M);
    map<long, char> ans;
    for(int i=0;i<N;++i){
        ans[(L/N)*i] = S[i];
    }
    bool check = true;
    for(int i=0;i<M;++i){
        if(ans[(L/M)*i]!=T[i] & ans[(L/M)*i]!='\0')check = false;
    }
    if(check)cout<<L<<endl;
    else cout<<-1<<endl;
}
