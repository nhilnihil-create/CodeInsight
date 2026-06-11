//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define PI acos(-1)
//#define m (pow(10, 9)+7)
typedef unsigned long long ull;
typedef long long ll;

int gcd(int a, int b){
    int temp;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    int h = gcd(2, n);
    int lcm = 2*n/h;

    cout << lcm << endl;



    return 0;
}
