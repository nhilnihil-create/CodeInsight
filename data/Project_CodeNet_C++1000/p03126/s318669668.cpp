#include <bits/stdc++.h>
 using namespace std; 
  int main (){
      int n,m;
      cin >> n >> m;
      vector<int> a(m*2);
      int ans=0;
      vector<int> k(n*2);
      int A[100][199];
      for(int i=0;i<n;i++){
        cin >> k.at(i);
         
           for(int j=0;j<k.at(i);j++){
             cin >> A[i][j];
         
             a.at(A[i][j])++;
              
             if(a.at(A[i][j])==n){ 
                 ans++;
                 
             }

         }
        
      }
      cout << ans << endl;
      return 0;
  }