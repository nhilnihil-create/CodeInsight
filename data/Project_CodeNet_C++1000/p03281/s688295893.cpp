#include <iostream>
using namespace std;

int main(void){
    int n, cnt=0, tmp;
    cin >> n;
    for (int i=1; i<=n; i+=2){
        tmp = 0;
        for (int j=1; j<=i; j++){
            if (i%j == 0) tmp += 1;
        }
        if (tmp == 8) cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
