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
    ios_base::sync_with_stdio(0);/*//*/
}

int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}



void readFromText(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

int main()
{
    quick();
//    readFromText();
    int a , b ; cin >> a >> b ;
    cout << (a-1)*(b-1);
    return 0;
}
