#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, k, i;
    map<long long, long long> mp;
    cin >> a >> b >> k;
    for(i=0;i<k;i++){
        if(a+i<=b)mp[a+i]++;
        if(b-i>=a)mp[b-i]++;
    }
    for(auto x : mp){
        cout << x.first <<endl;
    }
    return 0;
}