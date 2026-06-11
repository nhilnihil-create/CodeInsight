#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};

using namespace std;

void solve(){
      int n;
      cin>>n;
      vector<int>v(n+2);
      v[0]=0;
      v[n+1]=0;
      long long sum=0;
      for(int i=1;i<=n;i++){
          cin>>v[i];
          sum+=abs(v[i]-v[i-1]);
      }  
      sum+=abs(v[n+1]-v[n]);
     for(int i=1;i<=n;i++){
            cout<<(sum-abs(v[i]-v[i+1])-abs(v[i]-v[i-1])+abs(v[i+1]-v[i-1]))<<"\n";
      }
}

int main(){
   std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
   solve(); 
   return 0;
}
