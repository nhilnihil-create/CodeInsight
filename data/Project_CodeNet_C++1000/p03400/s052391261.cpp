#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d,x;
    cin >> n >> d >> x;
    
    int ans(0);
    for(int i=0;i<n;i++){
        int a;  cin >> a;
        for(int j=0;j<d;j++){
            if(j*a+1<=d){
                ans++;
            }
        }
    }
    ans += x;
    
    cout << ans << endl;
    
    return 0;
}
