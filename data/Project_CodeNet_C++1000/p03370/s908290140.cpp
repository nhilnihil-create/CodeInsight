#include <iostream>
//#include <string>
#include <vector>
//#include <cstdlib>
//#include <algorithm>
//#include <cmath>
using namespace std;
 
int main() {
    int N, X, M=1100;
    int sum=0;
    cin >> N >> X;
    
    vector<int> m(N);
    
    for(int i = 0; i<N; i++){
        cin >> m.at(i);
        sum += m.at(i);
        if(m.at(i) < M){
            M = m.at(i);
        } 
    }
    
    
    int ans = N + (X - sum) / M;
    //cout << sum << endl;
    //cout << M << endl;
    cout << ans << endl;
    return 0;
}