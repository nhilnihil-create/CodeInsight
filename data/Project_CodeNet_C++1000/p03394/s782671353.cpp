#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    int two[10002], three[5002], six[5002];
    int d;
    d = 2;
    for(int i = 0; i < 5000; i++){
        two[i * 2] = d;
        two[i * 2 + 1] = d + 2;
        d += 6;
    }
    d = 3;
    for(int i = 0; i < 5000; i++){
        three[i] = d;
        d += 6;
    }
    d = 6;
    for(int i = 0; i < 5000; i++){
        six[i] = d;
        d += 6;
    }
    int a = 2, b = 2, c = 0;
    while(a + b + c < n){
        if(a + b + c + 1 == n) c++;
        else if(a < 10000) a += 2;
        else if(b < 5000) b += 2;
        else c++;
    }
    for(int i = 0; i < a; i++) cout << two[i] << " ";
    for(int i = 0; i < b; i++) cout << three[i] << " ";
    for(int i = 0; i < c; i++) cout << six[i] << " ";
    cout << endl;
}
