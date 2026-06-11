#include <iostream>

using namespace std;

void solve(long long N){
    for(int n=1;n<=3500;n++){
        for(int h=1;h<=3500;h++){
            long long a = 4LL*n*h - N*(n+h);
            long long b = N*n*h;
            if(a <= 0) continue;
            if(b%a) continue;
            cout << n << " " << h << " " << b/a << endl;
            return;
        }
    }
}

int main(){
    long long N;
    while(cin >> N){
        solve(N);
    }
}