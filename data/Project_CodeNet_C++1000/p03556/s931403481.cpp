#include <bits/stdc++.h>
using namespace std;
bool is_sqrt(long long n) {
   if(floor(sqrt(n))==sqrt(n)) {
       return true;
   } else {
       return false;
   }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    for(int i = n;i > 0;i--) {
        if(is_sqrt(i)) {
            cout << i << endl;
            return 0;
        }
    }
}