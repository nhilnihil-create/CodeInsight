#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> mods(k, n/k);
    for(int i=0; i<n%k; ++i){
        ++mods[i+1];
    }
    long long ans=0;
    for(int i=0; i<k; ++i){
        if(i*2%k==0){
            long long m=mods[i];
            ans+=m*m*m;
        }
    }
    cout << ans << endl;
    return 0;
}
