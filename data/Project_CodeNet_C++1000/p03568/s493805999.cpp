#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N;cin >> N;
    int kisu=1;
    for(int i=0;i<N;i++){
        int n; cin >> n;
        if(n%2==0) kisu*=2;
    }
    cout << pow(3,N)-kisu << endl;
}
