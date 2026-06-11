#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m;cin>>n>>m;
    vector<pair<long,long>>ab;
    for(int i = 0;i<n;i++){
       int a,b;cin>>a>>b;
       ab.push_back(make_pair(a,b));
    }
    sort(ab.begin(),ab.end());
    long g = 0;
    for(int i = 0;i<n;i++){
      if(m <= ab[i].second){
         g+=m*ab[i].first;
         cout<<g;
         return 0;
      }
      else{
      	g+= ab[i].second*ab[i].first;
        m=m-ab[i].second;
      }
    }
    return 0;
}