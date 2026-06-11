#include <iostream>
using namespace std;

typedef unsigned long long ullong;

ullong N;
ullong P;

ullong prim_fact(ullong n) {
    ullong ans = 1;
    for(ullong i = 2; (i * i) <= P; i++){
        ullong cnt = 0;
        ullong p = P;
        while((p % i) == 0){
            cnt++;
            p /= i;
        }
        
        if(cnt >= N) {
            ans = i;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> P;
    
    if (N == 1) {
        cout << P << endl;
    } else {
        ullong count = prim_fact(P);
        
        cout << count << endl;
    }
    
    return 0;
}