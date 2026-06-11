#include <bits/stdc++.h>

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define MOD 1000000007
#define PI 3.14159265
#define endl '\n'
#define MAX 501
using namespace std;

void quick () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a , b ;
    cin >> a >> b ;
    if ((a*b*1%2!=0)||(a*b*2%2!=0)||(a*b*3%2!=0)){
        cout << "Yes" ;
    }else {
        cout << "No" ;
    }
    return 0;
}
