#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;



 
int main(){
    ll K, A, B; cin >> K >> A >> B;

    ll cnt = 1;
    if(A+2 >= B){
        cout << K+1 << endl;
        return 0;

    }

    else{
        for(int i = 0; i < K; i++){
            if(cnt == A) {
                int itr = (K-i)/2;
                int p = (K-i)%2;
                if(p == 1){
                    cnt += itr*(B-A) + 1;
                }
                else{
                    cnt += itr*(B-A);
                }
                break;
            }
            else cnt++;
        }
        cout << cnt << endl;
    }


}