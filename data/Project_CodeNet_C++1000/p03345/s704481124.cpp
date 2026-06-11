#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long A,B,C,K; cin >>A >> B>>C>> K;
    if(K%2 == 0) cout << A-B << endl;
    else cout << B-A << endl;
    
}
