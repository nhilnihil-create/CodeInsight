#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int X;
    cin >> X;
    
    //１の時は明らか
    if(X==1){
        cout << 1 << endl;
        return 0;
    }
    
    
    //２以上～３２までの探索でよいが，全探索する．
    int ans=0;
    for(int i=2; i<=32; i++){
        
        int j=2;
        while(pow(i,j)<=X){
            if(i*j <=X){
                int x = pow(i,j);
                ans = max(ans, x);
            }
            j++;
        }
    }
    
    cout << ans << endl;
}
