#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    for(int i=0; i<K; i++){
        if(i%2==0){
            if(A%2!=0){
                A--;
                A/=2;
                B+=A;
            }else{
                A/=2;
                B+=A;
            }
        }else{
            if(B%2!=0){
                B--;
                B/=2;
                A+=B;
            }else{
                B/=2;
                A+=B;
            }
        }
    }
    cout << A << ' ' << B;
}