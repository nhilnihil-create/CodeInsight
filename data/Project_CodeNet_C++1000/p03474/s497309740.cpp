#include <bits/stdc++.h>
using namespace std;

int main() {
int A,B;
string S;
cin >> A >> B >> S;
bool f=1;
for (int i = 0; i < A+B+1; i++)
{
    if(i==A)
    {
        if(S[i]!='-') f=0;
        continue;
    }
    if(isdigit(S[i]));
    else f=0;   
}

if(f) cout << "Yes" << endl;
else cout << "No" << endl;

return 0;
}
