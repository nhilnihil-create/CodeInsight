#include<iostream>
#include<string>
using namespace std;
int main() {
    int N;
    cin >> N;
    int x, y;
    x = N /4;
    y = N /7;

    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            int X = 4*i + 7*j;
            if(N == X){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}