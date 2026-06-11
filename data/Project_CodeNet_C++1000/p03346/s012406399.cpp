#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    int P[N];
    for(int i=0;i<N;++i){
        cin>>P[i];
        P[i]--;
    }
    int DP[N];
    for(int i=0;i<N;++i){
        DP[i] = 0;
    }
    for(int i=0;i<N;++i){
        if(P[i]==0)DP[0]++;
        else{
            if(DP[P[i]-1]>0) DP[P[i]] = DP[P[i]-1] + 1;
            else DP[P[i]] = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<N;++i){
        if(ans < DP[i])ans = DP[i];
    }
    cout<<N-ans<<endl;
}
