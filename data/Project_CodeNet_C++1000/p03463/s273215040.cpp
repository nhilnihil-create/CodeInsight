#include<iostream>

using namespace std;

int main()
{
    int N, A, B, i, x = 0, y = 0;

    cin >> N >> A >> B;

    for(i = 0; ; ++i) {

        A++;
        x++;

        if(B - A == 1)
            break;

        else if(B - A == 0) {

            cout << "Borys" << endl;

            return 0;
        }

        B--;
        y++;

    }

    if(x > y)
        cout << "Alice" << endl;

    else
        cout << "Borys" << endl;

    return 0;
}
