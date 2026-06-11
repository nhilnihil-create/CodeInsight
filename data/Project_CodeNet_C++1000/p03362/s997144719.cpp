#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0;
vector<ll> A;

void mydetect(int num) {
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) break;
        if((i+1)*(i+1)>num) A.push_back(num);
    }
}

void soinsuu() {
    int i=11;

    while(A.size()!=N) {
        mydetect(i);
        i+=5;
    }

    for(int j=0;j<A.size();j++) {
        cout << " " << A[j];
    }
}

signed main(){
    cin >> N;
    //A.push_back(2);
    soinsuu();
    return 0;
}