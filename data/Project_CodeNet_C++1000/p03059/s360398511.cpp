#include<bits/stdc++.h>
using namespace std;

int main() {
     int A,B,T,ans=0;
     cin >> A >> B >> T;
      for(int i=1;A*i<T+0.5;i++){
        ans+=B;
      }
      cout << ans << endl;
return 0;
}