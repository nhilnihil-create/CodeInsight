#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    char b, c;
    cin >> b;
    if(b == 'A') c = 'T';
    else if(b == 'T') c = 'A';
    else if(b == 'G') c = 'C';
    else c = 'G';
    cout << c;
    return 0;
}
