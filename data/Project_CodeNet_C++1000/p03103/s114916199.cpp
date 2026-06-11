#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(void){
    long long N,M;
    cin>>N>>M;
    vector<pair<int,int>> store(N);
    for(int i=0;i<N;i++){
        long long A,B;
        cin>>A>>B;
        store[i] = make_pair(A,B);
    }
    sort(store.begin(),store.end());
    long long ans = 0;
    long long count = 0;
    for(int i=0;count < M;i++){
        if(store[i].second > M - count){
            ans += store[i].first * (M - count);
            count = M;
        }
        else{
            count += store[i].second;
            ans += store[i].first * store[i].second;
        }
    }
    cout << ans << endl;
}
