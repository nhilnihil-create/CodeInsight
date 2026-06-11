#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int a,b,t;
    cin >> a >> b >> t;
    int sum=0;
    for(int i=1; i<=t/a; i++){
        sum+=b;
    }
    cout << sum << endl;
}