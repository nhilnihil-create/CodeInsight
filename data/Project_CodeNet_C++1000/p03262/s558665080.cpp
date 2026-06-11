#include <bits/stdc++.h>
using namespace std;
#define N_MAX 100000

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
//入力
int x[N_MAX];
int N,X;
int ans=0;

    cin >> N >> X;
    for(int i =0; i < N; ++i){
        cin >> x[i];
    }


    for(int i=0;i<N;i++){
        ans= gcd(ans,abs(x[i]-X));
    }

    cout <<ans <<endl;
    return 0;
}