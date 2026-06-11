#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    long long x,y,z;cin>>x>>y>>z;
    int k; cin>>k;
    long long a[x];
    long long b[y];
    long long c[z];
    vector<long long> ko;
    for(int i = 0;i<x;i++) cin >>a[i];
    for(int i = 0;i<y;i++) cin >>b[i];
    for(int i = 0;i<z;i++) cin >>c[i];
    sort(a,a+x,greater<long long>());
    sort(b,b+y,greater<long long>());
    sort(c,c+z,greater<long long>());
    for(int i = 0;i<x;i++){
     for(int j = 0;j<y;j++){
       for(int h = 0;h<z;h++){
           if((i+1)*(j+1)*(h+1)<=k){
              ko.push_back(a[i]+b[j]+c[h]);
           }
           else break;
       }
     } 
    }
    sort(ko.begin(),ko.end(),std::greater<long long>());
    for(int i = 0;i<k;i++){
      cout<<ko[i]<<endl;
    }
    return 0;
}