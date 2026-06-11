#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//imit
int main(void){
    long n,m;
    cin >> n >> m;
    
    vector<pair<long,long>> vec(n);//??
    
    for(int i = 0;i < n;i++){
          cin >> vec[i].first >> vec[i].second;
    }
    
    sort(vec.begin(),vec.end());//??
    
    long ans = 0;
    
    for(int i = 0;i < n;i++){
          ans += vec[i].first * min(m,vec[i].second);
          m -= min(vec[i].second,m);
          if(m == 0)break;
    }
    cout << ans << endl;
}
