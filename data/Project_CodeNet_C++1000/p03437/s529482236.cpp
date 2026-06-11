#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main(){
    long long int a,b;
    cin >> a >> b;
    if(a % b == 0){
        cout << -1 << endl;
        return 0;
    }
    if(lcm(a,b) == a){
        cout << -1 << endl;
        return 0;
    }

    for(long long int i = a; ; i += a){
        if(i % b != 0){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}