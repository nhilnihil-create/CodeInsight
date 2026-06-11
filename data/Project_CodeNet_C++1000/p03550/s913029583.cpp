#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll N,Z,W;
    ll a[2000];
    cin >> N >> Z >> W;
    for(int i=0;i<N;i++) cin >> a[i];
    if(N == 1){
        cout << abs(W-a[N-1]) << endl;
        return 0;
    }
    cout << max(abs(a[N-1]-a[N-2]),abs(W-a[N-1])) << endl;;
    return 0;
}