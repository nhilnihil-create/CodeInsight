#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long K,A,B; cin >> K >> A >> B;
    if(B-A <= 2){
        cout << K+1 << endl;
    }else if(K<=A-1){
        cout << K+1<< endl;
    }else{
        cout << A+((K-A+1)/2)*(B-A)+(K-A+1)%2 << endl;
    }
}
