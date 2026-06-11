#include <iostream>

using namespace std;

long long int GCD(long long int x, long long int y) {
    if(x<y) {
        swap(x, y);
    }
    if(y==0) {
        return x;
    }
    return GCD(y, x%y);
}

long long int LCM(long long int x, long  long int y) {
    return x/GCD(x, y)*y;
}

int main() {
    long long int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    bool flag=true;
    for(long long int i=0; i<GCD(N, M); i++) {
        flag = (S[i*N/GCD(N, M)]==T[i*M/GCD(N, M)]);
        if(!flag) {
            break;
        }
    }

    if(flag) {
        cout << LCM(N, M) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
    
}