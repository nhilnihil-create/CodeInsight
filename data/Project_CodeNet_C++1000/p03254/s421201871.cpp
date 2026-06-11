#include <bits/stdc++.h>
using namespace std;
int main() {
     int N,cost;
     cin >> N >> cost;
     std::vector<int> v;
     for(int i=0;i<N;i+=1){
          int x;
          cin >> x;
          v.push_back(x);
     }
     sort(v.begin(),v.end());
     int i=0;
     int ans = 0;
     while(v[i]<=cost && i<N){
          if(i==N-1){
               if(v[i]==cost){
                    ans+=1;
               }
               break;
          }
          
          ans+=1;
          cost-=v[i];
          i+=1;
          
     }
     cout << ans;
}
