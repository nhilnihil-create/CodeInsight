#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int N,K;
    cin >> N >> K;
    vector<int>dp(N,2e9);
    vector<int>h(N);
    for(long long int i=0;i<N;i++){
        cin >> h.at(i);
    }
    dp.at(0)=0;
    for(long long int i=1;i<N;i++){
        for(long long int m=1;m<=K;m++){
            if(i-m >=0){
                dp.at(i) = min(dp.at(i),dp.at(i-m)+abs(h.at(i-m)-h.at(i)));
            }
        }
    }
    cout << dp.at(N-1) << endl;

}