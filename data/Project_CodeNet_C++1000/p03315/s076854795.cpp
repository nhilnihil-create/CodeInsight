#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    int ans = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] == '+'){
            ans++;
        }
        else{
            ans--;
        }
    }
    cout << ans << endl;
}
