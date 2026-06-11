#include <iostream>
using namespace std;

int main(){
    long long n,a,b,c,d,e;
    cin >> n;
    long long nnum = 1e15;
    for(int i = 0; i < 5; i++){
        long long x; cin >> x;
        nnum = min(nnum, x);
    }
    long long ans = (n+nnum-1)/nnum;
    cout << 5 + (ans-1) << endl;
    return 0;
}