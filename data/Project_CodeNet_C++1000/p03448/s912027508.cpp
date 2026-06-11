#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int X;
    cin >> X;
    int cnt = 0;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            if(X - 500 * i - 100 * j >= 0 && (X - 500 * i - 100 * j) / 50 <= C) cnt++;
        }
    }
    cout << cnt << endl;
}