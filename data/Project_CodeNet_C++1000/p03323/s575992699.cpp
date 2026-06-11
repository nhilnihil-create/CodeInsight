#include<iostream>
using namespace std;
 
int main()
{
    int a,b;
    cin >> a>> b;
    
 

    int pizza = 16 - a - b;
    int meio = abs(a - b);
    if (pizza >= meio) {
        cout << "Yay!"<<endl;
    } else {
        cout << ":("<<endl;
    }
    return 0;
}