#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

long long MOD = 1000000007;

int main(){
    int N; cin >> N;
    ll ans=0, min_=MOD;
    int flag=1;
    for(int i=0; i<N; i++){
        ll A, B;
        cin >> A >> B;
        ans+=A;
        if(A>B){
            min_=min(min_, B);
        }
        if(A!=B){
            flag=0;
        }
    }
    if(flag==1){
        cout << 0 << endl;
        return 0;
    }
    cout << ans-min_ << endl;
  	return 0;
}