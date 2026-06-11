#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    
    int A, B;
    cin >> A >> B;
    
    int ans = 0;
    for(int i = A; i <= B; i++){
        string S = to_string(i);
        if(S[0] == S[4] && S[1] == S[3]) ans++;
    }
    
    cout << ans << endl;
}
