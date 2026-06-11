#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Value(int a){
    
    int total = 0;
    while(1){
        
        if( a%2 != 0 ) break;
        a /= 2;
        total++;
    }
    return total;
}
int main(){
    int N,A; cin >> N;
    ll sum = 0;
    for(int i=0;i<N;i++){ cin >> A; sum += Value(A); }
    cout << sum << endl;
}