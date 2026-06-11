#include<iostream>
#include<vector>
using namespace std;
long long fib(long long n)
{
    
    vector<long long >f(n+1);
    int i;

    
    f[0] = 2;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
int main() {
    long long n; cin >> n;
    cout<<fib(n);
  
    return 0;
}