#include <iostream>
typedef long long ll;
using namespace std;

int main(void) {
    string N;cin>>N;
    ll N_ll = stoll(N);
    string N1 = N.substr(0, 1);
    int sum = stoi(N1) - 1;
    while (N_ll >= 10) {
        sum += 9;
        N1 += "9";
        N_ll /= 10;
    }
    if (N1 == N) cout << sum + 1 << endl;
    else cout << sum << endl;
    return 0;
}