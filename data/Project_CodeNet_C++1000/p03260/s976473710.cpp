#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int A,B;
    bool odd = false;
    cin >> A >> B;

    for(int i = 1; i <= 3; i++)
        if(A*B*i % 2 == 1) odd = true;
    
    if(odd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    

    return 0;
}
