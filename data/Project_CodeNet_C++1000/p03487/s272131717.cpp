#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<long long,long long>mp;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    long long ans=0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        long long f = itr->first, s = itr->second;
       if(s<f){
           ans += s;
       }else{
           ans += s-f;
       }
    }
    cout << ans << endl;
    return 0;
}