#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
 double N,M,D;cin >> N >> M >> D;
 double ans = 0;
 if(D == 0){
   ans = (M-1) * (1/N);
 }else{
   ans = (M-1) * (2*(N-D)/(N*N));
 }
 cout << setprecision(25) << fixed;
 cout << ans << endl;
}
