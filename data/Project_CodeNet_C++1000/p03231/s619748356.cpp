#include <iostream>
#include <string>

using namespace std;

long long int GCD(long long int a, long long int b) {
    if(a<b) {
        long long int tmp=a;
        a = b;
        b = tmp;
    }
    
    if(b==0) {
        return a;
    }
    
    return GCD(b, a%b);
}

int main() {
    long long int N, M;
    cin >> N >> M;
    
    string S, T;
    cin >> S >> T;
    
    long long int sn=0, tn=0;
    bool flag=true;
    while(sn<N && tn<M) {
        if(S[sn]!=T[tn]) {
            flag = false;
            break;
        }
        
        sn += N/GCD(N, M);
        tn += M/GCD(N, M);
    }
    
    if(flag) {
        cout << N/GCD(N, M)*M << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
    
}