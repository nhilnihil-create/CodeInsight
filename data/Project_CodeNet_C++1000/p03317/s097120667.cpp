#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

   int n,p;
   cin>>n>>p;
   int min_index;int k = INT_MAX;
   for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    if(temp<k){
        k=temp;
        min_index=i;
    }
   }
  // cout<<min_index;
  int left =min_index;
  int right = n-min_index;
  cout<<(n-1+p-1-1)/(p-1);

 return 0;
}
