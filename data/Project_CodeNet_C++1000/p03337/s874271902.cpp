#include <iostream>

using namespace std;

int main(){
    int a, b, max;

    cin >> a >> b;

    max = a+b;

    if((a-b) > max){
        max = a-b;
    }
    if((a*b) > max){
        max = a*b;
    }   


    cout << max << endl;

    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       