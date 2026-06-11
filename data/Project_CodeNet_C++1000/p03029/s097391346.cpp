#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long        
using namespace std;
 
void scan()
{
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
 
}
const int N = 1e6 + 500;
const int mod = 1e9 + 7;

int main() 
{
    scan();     
    int a, b;
    cin >> a >> b;
    cout << (a * 3 + b) / 2;
}     
//JUDGE_ID: 295965SY
//Tis I