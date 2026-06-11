#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    int atob = b - a;
    if (atob < 0){
        atob *= (-1);
    }
    int btoc = c - b;
    if (btoc < 0){
        btoc *= (-1);
    }
    int atoc = c - a;
    if (atoc < 0){
        atoc *= (-1);
    }
    if (d >= atob && d >= btoc){
        cout << "Yes" << endl;
    }else if (d >= atoc){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
