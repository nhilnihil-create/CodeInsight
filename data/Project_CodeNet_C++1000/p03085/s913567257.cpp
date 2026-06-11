#include <iostream>

using namespace std;

int main() {
    char b, r;
    cin >> b;
    cout<<char((b=='A'||b=='T'?'A'+'T':'C'+'G')-b)<<endl;
}
