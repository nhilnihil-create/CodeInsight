#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < (int)n ; i++)
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int count = 0;

    for(int i=A; i <= B ; i++){
        int number = i;
        int number_1 = number % 10;//1の位
        number /= 10;//10の位
        int number_10 = number % 10;//10の位
        number /= 10;
        number /= 10;
        int number_1000 = number % 10;//1000の位
        number /= 10;
        int number_10000 = number % 10000;//10000の位

        if(number_1 == number_10000 && number_10 == number_1000){
            count++;
        }

    }

    cout << count << endl;
}