#include <bits/stdc++.h>
using namespace std;

int main()
{
int D; cin >> D;
string S = "Christmas";
for(int i = 24; i >= D; --i) {
    S += " Eve";
}
cout << S << endl;
}