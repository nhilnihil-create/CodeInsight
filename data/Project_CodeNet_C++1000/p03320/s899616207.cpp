#include <iostream>
using namespace std;
typedef long long ll;

double sunuke(ll n){
    double ds = 0.0;
    ll nn = n;
    while(nn > 0){
        ds += nn % 10;
        nn /= 10;
    }
    return n * 1.0 / ds;
}

int main()
{
    int k;
    cin >> k;
    ll pl = 1;
    ll now = 1;
    for(int i = 0; i < k; i++){
        if(sunuke(now) > sunuke(now + pl)){
            now -= pl;
            pl *= 10;
            now += pl;
        }
        cout << now << endl;
        now += pl;
    }
}