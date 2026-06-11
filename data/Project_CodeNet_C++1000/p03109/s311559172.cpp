#include <iostream>
using namespace std;

signed main()
{
    string s; cin >> s;
    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));

    if (y < 2019){
        puts("Heisei");
    } else if (y > 2019){
        puts("TBD");
    } else { // y==2019
        if(m <= 4){
            puts("Heisei");
        } else {
            puts("TBD");
        }
    }

    return 0;
}
