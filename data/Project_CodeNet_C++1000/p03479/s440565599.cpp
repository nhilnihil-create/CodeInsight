#include <iostream>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll a, b, c=1;
    std::cin >> a >> b;
    while(a*2<=b){
        c++;
        a*=2;
    }
    std::cout << c << endl;
    return 0;
}