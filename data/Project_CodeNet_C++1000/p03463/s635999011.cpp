#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  if((A - B) % 2 == 0){
    cout << "Alice" << endl;
  }else{
    cout << "Borys" << endl;
  }
}
