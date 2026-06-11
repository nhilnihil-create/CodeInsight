#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
string S;
cin >> S;
int nen = (S.at(0) - '0') * 1000 + (S.at(1) - '0') *100 + (S.at(2) - '0') *10 + (S.at(3) -'0');
int tuki = (S.at(5) - '0') *10 + (S.at(6) - '0');
if (nen < 2019) cout << "Heisei" << endl;
else if (nen > 2019) cout << "TBD" << endl;
else if (tuki <= 4) cout << "Heisei" << endl;
else if (tuki > 4) cout << "TBD" << endl;



return 0;
}
