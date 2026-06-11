#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    ll a = A,b = B,c = C,d = D,e =E;

    while(a % 10 != 0) if(a % 10 != 0) a++;
    while(b % 10 != 0) if(b % 10 != 0) b++;
    while(c % 10 != 0) if(c % 10 != 0) c++;
    while(d % 10 != 0) if(d % 10 != 0) d++;
    while(e % 10 != 0) if(e % 10 != 0) e++;
    
    ll ans1,ans2,ans3,ans4,ans5;
    ans1 = A + b + c + d + e;
    ans2 = a + B + c + d + e;
    ans3 = a + b + C + d + e;
    ans4 = a + b + c + D + e;
    ans5 = a + b + c + d + E;

    cout << min(ans1,min(ans2,min(ans3,min(ans4,ans5)))) << endl;
}