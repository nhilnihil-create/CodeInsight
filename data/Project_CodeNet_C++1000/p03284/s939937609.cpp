#include <iostream>

using namespace std;

int main()
{

    int atcoder, user;
    cin >> atcoder >> user;

    if (atcoder % user == 0){
        cout << 0 << endl;
    }

    else {
        cout << 1 << endl;
    }

    return 0;
}
