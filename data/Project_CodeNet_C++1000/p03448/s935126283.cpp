#include <iostream>
using namespace std;

int main(){
    int A, B, C, X;
    int count = 0;
    cin >> A >> B >> C >> X;
    X /= 50;
    for(int i = 0; i < A + 1; i++){
        for(int f = 0; f < B + 1; f++){
            for(int g = 0; g < C + 1; g++){
                if(X == (10 * i + 2 * f + g )) count++;
            }
        }
    }
    cout << count << endl;
}