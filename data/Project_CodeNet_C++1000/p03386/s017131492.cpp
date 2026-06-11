#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int A,B,K; cin >> A >> B >> K;
    for(int i=A;i<=B;i++){
        if(i<A+K || i>B-K) cout << i << endl;
    }
}

