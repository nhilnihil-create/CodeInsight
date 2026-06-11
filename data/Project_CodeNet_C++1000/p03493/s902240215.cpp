#include <iostream>
using namespace std;

int main(void) {
    string a;
    int cnt = 0;
    cin >> a ;

    for(int i = 0; i < a.length() + 1; i++){
    switch (a[i])
    {
    case '1':
    cnt += 1;
        break;

    case '0':
        break;
        }
    }

    cout << cnt << endl;


    return 0;
}
