#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll A,B,K;
    vector<ll> num(300,0);
    vector<ll> num2(300,0);
    cin >> A >> B >> K;

    for(int i = A; i < min(B ,A + K); i++){
        num[i - A] = 1;
    }
    if(B - A <= 100){
        for(int i = A ; i < min(B ,A + K); i++){
            num[i - A] = 1;
        }
        for(int i =  max(A,B - K + 1); i <= B; i++){
            num[i - A] = 1;
        }


        for(int i = A; i <= B; i++){
            if(num[i - A] == 1) cout << i << endl;
        }
        return 0;
    }else{
        for(int i = B - K + 1; i <= B; i++){
            num2[i - (B - K + 1)] = 1;
        }

        for(int i = A; i <= A + K; i++){
            if(num[i - A] == 1) cout << i << endl;
        }

        for(int i = B - K + 1; i <= B; i++){
            if(num2[i - (B - K + 1)] == 1) cout << i << endl;
        }
    }


}
