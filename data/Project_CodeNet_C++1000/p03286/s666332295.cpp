#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(N) for (int i = 0; i < N; i++)

int main(){
    long N;
    cin >> N;
    string N_binary = "";
    long N_mod, x;
    long N_defined = -1;
    long two_pow = 1;
    long minus_two_pow = 1;
    long index = 1;
    while (N != N_defined){
        two_pow *= 2;
        if (index == 1){
            if (N % 2 == 0){
                N_binary = "0" + N_binary;
                N_defined = 0;
            }else{
                N_binary = "1" + N_binary;
                N_defined = 1;
            }
        }else{
            minus_two_pow *= -2;
            N_mod = N % two_pow;
            x = (N_mod - N_defined) / minus_two_pow;
            //cout << "index: " << index << ",N_mod: " << N_mod << ",N_defined: " << N_defined << ",minus_two_pow: " << minus_two_pow << ",x: " << x << endl;
            if (x % 2 == 0){
                N_binary = "0" + N_binary;
                N_defined += 0;
            }else{
                N_binary = "1" + N_binary;
                N_defined += minus_two_pow;
            }
        }
        index++;
    }
    cout << N_binary << endl;
}
