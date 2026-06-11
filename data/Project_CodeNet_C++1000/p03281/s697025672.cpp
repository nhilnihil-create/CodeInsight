#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, ans=0; cin >> N;
    for (int n=1; n<=N; n++){
        int cnt=0;
        if (n%2!=0){
            for (int i=1; i<=n; i++){
                if (n%i==0) cnt++;
            }
        }
        if (cnt==8) ans++;
    }
    cout << ans << endl;

}