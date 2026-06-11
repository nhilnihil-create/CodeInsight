#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
    int N; cin >> N;
    if(N==1){
        cout << "Hello World" << endl;
    }else{
        int A,B; cin >> A >> B;
        cout << A+B << endl;
    }
}
