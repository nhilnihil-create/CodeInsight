#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int p = a + b;
    int t = a * b;
    if(p == 15){
        cout << "+" << endl;
    }else if(t == 15){
        cout << "*" << endl;
    }else{
        cout << "x" << endl;
    }
    return 0;
}
