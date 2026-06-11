#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int reverce(int n){
    int reverced_num = 0;
    int digit = pow(10, to_string(n).length()-1);

    while(n){
        reverced_num += (n % 10) * digit;
        n /= 10;
        digit /= 10;
    }
    return reverced_num;
}

int main(){
    int A, B, reverced_num, count = 0;
    cin >> A;
    cin >> B;

    for (int i = A; i <= B; i++){
        reverced_num = reverce(i);
        if(reverced_num == i) count++;
    }

    cout << count << endl;
    return 0;
}