#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int u[100]; fill(u, u + 100, 0);
    int ans = 0;
    for(int i=0; i<N; i++){
        int d;
        cin >> d;
        d--;
        if(u[d] == 0) ans ++;
        u[d] ++;
    }    
    cout << ans << endl;
    return 0;
}