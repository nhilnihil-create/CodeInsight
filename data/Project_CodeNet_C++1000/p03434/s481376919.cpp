#include <bits/stdc++.h>
using namespace std;

int main(){

      long n,Alice=0,Bob=0;
      cin>>n;
      int a[n];

      for(int i=0;i<n; i++){
        cin>>a[i];
      }

      sort(a,a+n);

      for(int i=0;i<n;i++){
        if(i%2 == 0){
          Bob+= a[i];
        }
        else{
          Alice+= a[i];
        }
      }

      cout<<abs(Bob-Alice)<<endl;

      return 0;
}
