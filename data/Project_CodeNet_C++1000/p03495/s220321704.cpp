#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> amap;
    for(int i=0;i<n;i++){
        int ai;
        cin>>ai;
        amap[ai]++;
    }
    vector<int> asort;
    for(const auto& item:amap){
        asort.push_back(item.second);
    }
    sort(asort.begin(),asort.end());
    int val=amap.size();
    int ans=0;
    int index=0;
    while(val>k){
        ans+=asort[index];
        val--;
        index++;
    }
    cout<<ans<<endl;
    return 0;
}