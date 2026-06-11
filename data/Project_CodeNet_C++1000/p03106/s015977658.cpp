#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int cnt=0;
    int ans=0;
    
    for(int i=0;i<100;++i){
            int j=100-i;
            if(a%j==0 && b%j==0) {
                cnt++;}
            if(cnt==k) {
              ans=j;
              break;}
        }
        cout << ans << endl;
        return 0;
    }
