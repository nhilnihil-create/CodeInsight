#include <iostream>

using namespace std;

int main()
{
    char a , c , g , t ,b;
    a='A';
    c='C';
    g='G';
    t='T';
    cin>> b;
    if (b==a) {
        cout<< t;
    }
    if (b==t) {
        cout<< a;
    }
    if (b==g) {
        cout<< c;
    }
    if (b==c) {
        cout<< g;
    }

    return 0;
}
