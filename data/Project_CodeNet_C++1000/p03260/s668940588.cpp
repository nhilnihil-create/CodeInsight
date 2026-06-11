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
    bool state = false ;
    for (int i = 1 ; i <= 3 ; i++){
        if (a*b*i%2!=0)state=true;
    }
    if (state){
        cout << "Yes";
    }else {
        cout << "No";
    }
    return 0;
    return 0;
}
