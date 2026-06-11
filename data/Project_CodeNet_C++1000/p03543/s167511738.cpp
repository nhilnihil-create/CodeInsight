#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int num1 = N % 10;//1
    int num1000 = N / 1000;//1000
    N = N / 10;
    int num10 = N % 10;//10
    N = N / 10;
    int num100 = N % 10;//100

    if((num1 == num10 && num10 == num100) || (num10 == num100 && num100 == num1000)){
             cout << "Yes" << endl;   
    }else{
        cout << "No" << endl;
    }
}