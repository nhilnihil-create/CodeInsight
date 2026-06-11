#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  ll X,Y;
  cin >> X >> Y;
  if(X % Y == 0){
    cout << -1 << endl;
    return 0;
  }else{
    cout << X << endl;
    
  }
}