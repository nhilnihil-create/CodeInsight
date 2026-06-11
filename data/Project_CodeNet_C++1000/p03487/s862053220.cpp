#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
    map<long long, long long> m;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        m[a]++;
    }
    long long ans = 0;
    for(auto v: m){
        if(v.second < v.first) ans += v.second;
        else ans += v.second - v.first;
    }
    cout << ans << endl;
}