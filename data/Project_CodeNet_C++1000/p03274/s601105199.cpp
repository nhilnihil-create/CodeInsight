#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
    int N,K;
    cin >> N >> K;
    int x[N];
    for(int i=0;i<N;i++)cin>>x[i];
    vector<int> y,z;
    for(int i=0;i<N;i++){
        if(x[i] < 0){
            y.push_back(x[i]);
        }
        else{
            z.push_back(x[i]);
        }
    }
    sort(y.begin(),y.end(),greater<>());
    int ans = 2100000000;
    if(z.size() >= K){
        ans = min(ans,z[K-1]);
    }
    if(y.size() >= K){
        ans = min(ans,abs(y[K-1]));
    }
    
    for(int i=0;i<K;i++){
        int tmpans;
        if(i < z.size() && K - i - 2 < y.size()){
            tmpans = z[i]*2+abs(y[K-i-2]);
            ans = min(ans,tmpans);
        }
        if(i < y.size() && K-i-2 < z.size()){
            tmpans = abs(y[i]*2)+z[K-i-2];
            ans = min(ans,tmpans);
        }
    }
    cout << ans;
}
