#include<iostream>

using namespace std;

int main(){
    char a;
    cin >> a;
    if(a=='A')
    {
        cout << "T" << endl;
    }
    else if (a=='C')
    {
        cout << "G" << endl;
    }
    else if (a=='G')
    {
        cout << "C" << endl;
    }
    else if (a=='T')
    {
        cout << "A" << endl;
    }
    return 0;
}