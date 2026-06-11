#include <iostream>

using namespace std;

int main()
{
    int A , B , X ;
    cin >> A >> B >> X ;
    if((X - A)>= 0 && (A + B -X)>= 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
