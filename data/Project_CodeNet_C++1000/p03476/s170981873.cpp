#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>

bool prime_num(T x){
    if(x == 1) return false;
    for(T i=2; i<=T(sqrt(x)); i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    int Q;
    cin >> Q;
    int r[Q], l[Q];
    int max_r = 0;

    for(int i=0; i<Q; i++){
        cin >> l[i] >> r[i];
        max_r = max(max_r, r[i]);
    }
    int cnt[max_r + 2]; 
    cnt[1] = 0;

    for(int i=3; i<max_r + 2; i+=2){
        cnt[i] = cnt[i-2];
        if(prime_num(i) && prime_num((i+1)/2)) cnt[i]++;
    }   
    
    for(int i=0; i<Q; i++){
        if(l[i] == 1){
            cout << cnt[r[i]] << endl;
        }
        else{
            cout << cnt[r[i]] - cnt[l[i] - 2] << endl;
        }
    }
    return 0;
}