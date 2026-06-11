#include <iostream>
using namespace std;

int main(void) {
    int A,B,C,D;cin>>A>>B>>C>>D;
    int AB = A + B;
    int CD = C + D;
    if (AB > CD) cout << "Left" << endl;
    else if (AB < CD) cout << "Right" << endl;
    else cout << "Balanced" << endl;
    return 0;
}