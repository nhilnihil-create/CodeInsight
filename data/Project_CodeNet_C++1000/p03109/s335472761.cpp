#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    if (S[5] == '0' && (S[6] == '1' || S[6] == '2' || S[6] == '3' || S[6] == '4')) printf("%s\n", "Heisei");
    else printf("%s\n", "TBD");
}