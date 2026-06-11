#include <iostream>
#include <vector>
using namespace std;


int main(void){
    string s;
    cin >> s;
    int ans = 1000;
    for(int i = 0;i < s.size() - 2;i++){
        int t = stoi(s.substr(i,3));
        ans = min(ans,abs(t - 753));
    }
    cout << ans << endl;
    
}
