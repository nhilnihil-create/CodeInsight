#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    map<int,int> m;
    for(int i=a;i<a+k;i++){
        m[min(i,b)]++;
    }
    for(int i=b;i>b-k;i--){
        m[max(i,a)]++;
    }
    for(auto x:m){
        cout << x.first << endl;
    }
}