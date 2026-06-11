#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
    cin >> N;
    
    int64_t ans0 = 2;
    int64_t ans1 = 1;
    int64_t ans;
    
    if (N == 1){
        cout << 1 << endl;
    }
    else {
        for (int i=1;i<N;i++) {
            ans = ans0 + ans1;
            ans0 = ans1;
            ans1 = ans;
            
        }
        cout << ans << endl;
    }
    
   }

 