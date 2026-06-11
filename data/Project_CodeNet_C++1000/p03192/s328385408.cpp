#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    int ans = 0;
    for(int i=0;i<S.size();i++){
        if(S[i] == '2')ans++;
    }
    cout << ans;
}
