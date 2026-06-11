#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    long long cnt = 0;
    long long flag = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A') flag++;
        else if(i + 1 < S.size() && S[i] == 'B' && S[i + 1] == 'C') {
            cnt += flag;
            i++;
        }
        else flag = 0;
    }
    cout << cnt << endl;
}