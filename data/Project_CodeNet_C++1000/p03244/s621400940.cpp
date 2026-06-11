#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;


int main(){
   int n;
   cin >> n;
   vector<int> v(n);
   rep(i,n) cin >> v[i];
   map<int,int> odd;
   map<int,int> even;
   int odd1=0;
   int o1 = 0;
   int odd2=0;
   int o2 = 0;
   int even1=0;
   int e1 = 0;
   int even2=0;
   int e2 = 0;
   //奇数,偶数
   rep(i,n){
       if(i%2==0){
           odd[v[i]]++;
       }
       else{
           even[v[i]]++;
       }
   }
   for(auto a:odd){
       if(a.second>odd1){
           odd2 = odd1;
           o2 = o1;
           odd1 = a.second;
           o1 = a.first;
       }
       else if(a.second>odd2)
            odd2 = a.second;
   }
    for(auto a:even){
       if(a.second>even1){
           even2 = even1;
           e2 = e1;
           even1 = a.second;
           e1 = a.first;
       }
       else if(a.second>even2)
            even2 = a.second;
   }
    if(e1!=o1){
        cout << n-odd1-even1 << endl;
    }
    else{
        cout << min(n-even1-odd2,n-even2-odd1) << endl;
    }
    return 0;

}