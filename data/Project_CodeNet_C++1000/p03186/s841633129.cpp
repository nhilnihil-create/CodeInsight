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
  ll A,B,C;
  cin >> A >> B >> C;
  if(A+B+1 >= C){
    cout << B + C << endl;
  }else{
    cout << B + B + A + 1 << endl;
  }
}