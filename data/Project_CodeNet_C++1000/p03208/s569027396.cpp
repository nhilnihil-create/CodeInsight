#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i!=(n);++i)

typedef long long ll;

using namespace std;

int main(){

    int N,K;
    cin>>N>>K;

    int h[N];

    rep(i,N) cin>>h[i];

    sort(h,h+N);
    int Min=1000000000;
    int a;

    for(int i=0;i!=N-K+1;++i){
        a=h[i+K-1]-h[i];
        Min=(Min<=a)?Min:a;
    }

    cout<<Min<<endl;
}

