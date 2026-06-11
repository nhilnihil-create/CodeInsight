#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,ans=0,a,b,ren=1;
    cin >> N;
    cin >> a;
    for(int i=1;i<N;i++){
        cin >> b;
        if(a==b){
            ren++;
        }else{
            ans += ren/2;
            a = b;
            ren = 1;
        }
    }

    ans += ren/2;

    cout << ans << endl;
}