#include <iostream>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    int cnt = 0;
    for(int i = 0; i < S.size(); i++) if(S[i] == 'o') cnt++;
    
    int ans = 700 + (100 * cnt);
    cout << ans << endl;
    
}
