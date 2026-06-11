#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll L[100];
bool seen[100];

ll Lucas(int N){
    if(seen[N]==true||L[N]!=-1)return L[N];
    seen[N]=true;
    L[0]=2;
    L[1]=1;
    if(N!=1&&N!=0)L[N]=Lucas(N-1)+Lucas(N-2);    
    return L[N];
}

int main(){
    int N;
    cin>>N;
    rep(i,100){
        seen[i]=false;
        L[i]=-1;
    }
    cout<<Lucas(N)<<endl;
    return 0;
}