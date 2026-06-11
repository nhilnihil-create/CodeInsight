#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long a[N];
    map<long long,long long> bucket,used;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        bucket[a[i]]++;
    }
    long long ans = 0;
    for(int i =0; i < N; i++){
        if(used[a[i]]) continue;
        if(a[i] <= bucket[a[i]]){
            ans += bucket[a[i]] - a[i];
        }
        else ans += bucket[a[i]];
        used[a[i]] = 1;
    }
    cout << ans << endl;
}