#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int ans=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        mp[a]++;
        if(a>100000){
            ans++;
        }
    }
    for(int i=1;i<100001;i++){
        if(mp.count(i)){
            if(mp[i]>=i){
                ans+=mp[i]-i;
            }
            else{
                ans+=mp[i];
            }
        }
    }
    cout << ans << endl;
}
