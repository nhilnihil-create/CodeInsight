#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){

 string s;
 cin>>s;
 int n=s.size();
 int ct=0;
 ll sum=0;
 for(int i=0;i<n;i++){

     if(s[i]=='W'){
         sum+=(i-ct);
         ct++;
     }
 }
 
cout<<sum<<endl;



}