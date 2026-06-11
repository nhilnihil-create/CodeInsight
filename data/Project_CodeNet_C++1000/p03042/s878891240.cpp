#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a;
  cin >> a;
  int b = a/100,c= a%100;
  if(1<=b&&b<=12){
        if(1<=c&&c<= 12)cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }else{
        if(1<=c&&c<=12)cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
} 
