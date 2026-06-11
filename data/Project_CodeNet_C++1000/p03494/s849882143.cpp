#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N;

    cin >> N;

    int a[N];

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool flg = true;
    do{ 
        for (int i = 0; i < N; i++) {
            if(a[i] % 2 == 0){
                a[i] = a[i] / 2;

            }else{
                flg = false;
            }
        }
        if(flg){
            cnt++;
        }
    }while (flg);

    cout << cnt << endl;

    return 0;

}



