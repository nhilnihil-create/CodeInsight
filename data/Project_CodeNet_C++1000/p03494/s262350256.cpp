#include <iostream>
#include <string>
#define Max 50
using namespace std;

int main() {
    int s,cnt = 0,flg = 0;
    cin >> s;
    int  t[s];
    
    for(int i = 0; i < s; i++){
        cin >> t[i];
    }
    
    for(int j = 0 ; j < Max; j++){
    for(int i = 0; i < s; i++){
        if(t[i] % 2 != 0) {
            flg = 1;
            break;
        }
        t[i] = t[i] / 2;
    }
        if(flg == 1) break;
        cnt++;
    }

    cout << cnt << endl;
}
