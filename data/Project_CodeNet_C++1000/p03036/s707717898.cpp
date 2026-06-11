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
    int r, d;
    cin >> r >> d;
    int x;
    cin >> x;
    for (int i = 1; i <= 10; i++)
    {
    	x = x * r - d;
    	cout << x << "\n";
    }

}     
//JUDGE_ID: 295965SY
//Tis I