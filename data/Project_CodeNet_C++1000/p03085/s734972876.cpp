#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 char b;
 cin >> b;
 if(b == 'A') b = 'T';
 else if(b == 'T') b = 'A';
 else if(b == 'G') b = 'C';
 else if(b == 'C') b = 'G';


 cout << b;

    return 0;
}