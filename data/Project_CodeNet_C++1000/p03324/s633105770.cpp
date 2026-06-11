#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int D,N;
    cin >> D >> N;
    if(D == 0){
        if(N != 100)cout << N << endl;
        else cout << 101 << endl;
        return 0;
    }
    int x = 1; for(int i = 0; i < D; ++i) x *= 100;
    if(N != 100)cout << x*N << endl;
    else cout << x*101 << endl;
    return 0;
}