#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    long n,m;
    cin>>n>>m;
    pair<long,long> CB[n+m];
    for(int i = 0;i<n;i++) {
      int a;cin>>a;
      CB[i] = make_pair(a,1);
    }
    for(int i = n;i<n+m;i++){
      int b,c;cin>>b>>c;
      CB[i] = make_pair(c,b);
    }
    sort(CB,CB+n+m,greater<>());
    long g = 0;
    long mg = 0;
    for(int i = 0;i<n;i++){
       g+= CB[i].first*CB[i].second;
       mg+= CB[i].second;
       if(mg > n){
        long sa = mg-n;
        g-= sa*CB[i].first;
        mg = n;     
       }
       if(mg == n){
         cout<<g;
         return 0;
       }     
    }
    return 0;
}