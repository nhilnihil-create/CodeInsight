#include<bits/stdc++.h>
using namespace std;
int main (){
int N, K;
cin >> N >> K;
int count = 0;
int x = N - K ;
int k = K - 1;
if(x % k == 0) cout <<( x / k) +1 << endl;
else cout << (x / k )+2 << endl;
}