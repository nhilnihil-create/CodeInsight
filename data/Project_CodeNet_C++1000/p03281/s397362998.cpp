#include <bits/stdc++.h>
using namespace std;
     
#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    int N,cnt=0,ans=0;
    cin >> N;
    for(int i=2;i<=N;i++){
        if(i%2!=0){
            for(int j=1;j<=i/2;j++){
                if(i%j==0){
                    cnt++;
                }
            }
            if(cnt == 7){
                ans++;
            }
            cnt = 0;
        }
    }
    cout << ans << endl;
}