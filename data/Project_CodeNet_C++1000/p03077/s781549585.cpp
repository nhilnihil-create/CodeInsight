#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long N; cin >> N;
    long long m=pow(10,15)+10;
    for(int i=0;i<5;i++){long long n; cin >> n; if(n<m) m=n;}
    cout << 5+(N-1)/m<<endl;
}
