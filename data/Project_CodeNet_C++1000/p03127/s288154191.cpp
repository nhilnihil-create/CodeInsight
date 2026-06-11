#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    int ans=a.at(0);
    for(int i=1;i<n;i++){
        ans=gcd(ans,a[i]);
    }
    cout << ans << endl;
}