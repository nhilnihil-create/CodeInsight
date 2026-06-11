#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    for(long long i=1;i<=3500;i++){
        for(long long j=1;j<=3500;j++){
            long long ww=4*i*j-n*i-n*j;
            if(ww!=0&&(n*i*j)%ww==0){
                long long w=(n*i*j)/ww;
                if(w>0){
                    cout << i << " " << j << " " << w << endl;
                    return 0;
                }
            }
        }
    }
}