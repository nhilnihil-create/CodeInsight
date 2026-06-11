#include<iostream>
#include<string>
using namespace std;
int main() {
    int A, B, C;
    int X;
    cin >> A >> B >> C;
    cin >> X;
    int c = 0;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k <= C; k++){
                int Y = 500*i + 100*j + 50* k;
                if(X == Y) c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}