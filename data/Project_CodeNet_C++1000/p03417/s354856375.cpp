#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long N, M;
    cin >> N >> M;
    if(N * M == 1) {
        cout << 1 << endl;    
        return 0;
    }
    if(min(N, M) == 1){
        cout << max(N, M) - 2 << endl;
        return 0;
    }
    cout << (N - 2) * (M - 2) << endl;
    return 0;
}