#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    long long N;
    cin >> N;
    for(long double i = 1;i<3501;i++){
        for(long double j = 1;j<3501;j++){
            if(4 * i * j - N * i - N * j == 0) continue;
            long double k = N * i * j / (4 * i * j - N * i - N * j);
            if(k > 0 && k == ceil(k)){
                cout << setprecision(20) << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    
    return 0;
}