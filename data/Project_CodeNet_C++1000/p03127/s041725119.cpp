#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b){
  if(b== 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
    long long n;
    cin >> n;
    long long a[n];

    for(long long i = 0; i < n; i++) cin >> a[i];

    long long g;
    for(long long i = 0; i < n; i++){
        if(i == 0){
            g = gcd(a[i], a[i+1]);
        }
        else{
            g = gcd(g, a[i]);
        }
    }

    cout << g << endl;
    return 0;
}