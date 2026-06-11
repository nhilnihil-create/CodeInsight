#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    int c = 0;
    while(n != 0){
        if(n%10 == 2) c++;
        n/=10;
    }
    cout << c << endl;
    return 0;
}