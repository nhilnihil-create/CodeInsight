#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long

using namespace std;
typedef pair<int,int> P;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> emap;
    map<int,int> omap;

    for(int i=0;i<n;i++){
        if(i%2==0){
            emap[a[i]]++;
        }else{
            omap[a[i]]++;
        }        
    }
    vector<P> epairs;
    vector<P> opairs;
    for(const auto& item:emap){
        epairs.emplace_back(item.second,item.first);
    }    
    
    for(const auto& item:omap){
        opairs.emplace_back(item.second,item.first);
    }
    epairs.emplace_back(0,0);
    opairs.emplace_back(0,0);

    sort(epairs.begin(),epairs.end(),greater<>());  
    sort(opairs.begin(),opairs.end(),greater<>());   
    if(opairs[0].second==epairs[0].second){
        cout<<n-max(epairs[0].first+opairs[1].first,epairs[1].first+opairs[0].first)<<endl;
    }else{
        cout<<n-epairs[0].first-opairs[0].first<<endl;  
    }          
    
    return 0;
}