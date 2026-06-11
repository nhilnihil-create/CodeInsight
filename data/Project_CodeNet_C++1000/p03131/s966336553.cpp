#include <bits/stdc++.h>
using namespace std;
int main(void){
    long k,a,b;
    cin >> k >> a >> b;
    cout << max(k+1,((k-a+1)/2)*(b-a)+a+(k-a+1)%2) << endl;
}