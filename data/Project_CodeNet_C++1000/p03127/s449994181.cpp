#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#define DBL_MIN 0.000000000000001
 
#define A_P(n,a,d) (n/2)*(2*a + (n-1)*d)
using namespace std;
 
//ちゃんとlong型でやってる？
 long euclidean_gcd(long a, long b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main(void){
    int N;
    cin >> N;

    int neko;
    cin >> neko;
    for(int i =0; i < N -1; i++){
        int tmp;
        cin >> tmp;
        if(tmp % neko){
            neko = euclidean_gcd(neko,tmp);
        }
    }

    cout << neko << endl;
    return 0;
}