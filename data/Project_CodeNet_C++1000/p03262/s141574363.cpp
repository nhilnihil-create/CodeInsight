#include <bits/stdc++.h>
using namespace std;

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

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main(){
    
    int n,X;
    cin >> n >> X;
    int num;
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> num;
        d.at(i)=abs(X-num);
    }

    int ans=d.at(n-1);
    for(int i=0; i<n-1; i++){
        ans=gcd(ans,d.at(i));
        //cout << ans << endl;
    }
    cout << ans << endl;
}