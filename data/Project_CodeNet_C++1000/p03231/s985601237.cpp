#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mygcd(int a, int b){
    if(a < b){
        int t = a; a = b; b = t;
    }
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;

    long long int ans = mygcd(n, m);
    ans *= n/mygcd(n, m);
    ans *= m/mygcd(n, m);

    long long int n1 = ans/n, m1 = ans/m;
    for(long long int i = 0; i*n1 < ans; i++){
        if(n1*i % m1 != 0) continue;
        long long int ind = (n1*i)/m1;
        if(s[i] != t[ind]) ans = -1;
    }
    cout << ans << endl;
    return 0;
}