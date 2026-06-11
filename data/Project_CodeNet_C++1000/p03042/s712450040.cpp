#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    int a = (S[0] - '0') * 10 + (S[1] - '0'), b = (S[2] - '0') * 10 + (S[3] - '0');
    if ((1 <= a && a <= 12) && (1 <= b && b <= 12)) printf("%s\n", "AMBIGUOUS");
    else if (1 <= b && b <= 12) printf("%s\n", "YYMM");
    else if (1 <= a && a <= 12) printf("%s\n", "MMYY");
    else printf("%s\n", "NA");
}
