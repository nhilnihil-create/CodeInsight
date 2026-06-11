#include <iostream>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2]) {
        cout<< "No";
    }
    else{
        cout<< "Yes";
    }
    return 0;
}
