#include <iostream>
#include <string>

using namespace std;

long long int GCD(long long int a, long long int b) {
    if(a<b) {
        long long int tmp=a;
        a=b;
        b=tmp;
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
    
    long long int gcd=GCD(N, M);
    long long int ans=N/gcd*M;
    for(long long int i=0; i<gcd; i++) {
        if(S[N/gcd*i]!=T[M/gcd*i]) {
            ans = -1;
            break;
        }
    }
    
    cout << ans << endl;


    return 0;
    
}