#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll A;cin >> A;
if((A/10)%111 == 0){cout << "Yes";exit(0);}
if((A - (A/1000)*1000)%111 == 0){cout << "Yes";exit(0);}
cout << "No";
}