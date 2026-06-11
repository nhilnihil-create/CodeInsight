#include <iostream>
#include<sstream>
#include<string>
#include<vector>
#include <cmath>
#include <limits>
#include <queue>
#include<algorithm>
#include<cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <memory>
#include <numeric>
#include <type_traits>
 
using namespace std;
 
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
typedef long long ll;
vector<int> prime, res;
const int VMAX = 55555;

bool is_prime(int num){
    if (num < 2) return false;
    else if (num == 2 || num == 3) return true;
    rep(i,prime.size()){
        if (num%prime[i] == 0) return false;
    }
    int temp = prime.back();
    while (temp < num){
        if (num%temp == 0) return false;
        ++temp;
    }
    return true;
}

void make_primes(){
    rep(i,VMAX+1){
        if (is_prime(i)) prime.push_back(i);
    }
}



 
int main() {
    int n;
    cin >> n;
    make_primes();
    int i = 0;
    while (n > 0){
        string s = to_string(prime[i]);
        char s_back = s[s.length()-1];
        if (s_back == '1'){
            cout << s << " ";
            n -= 1;
        }
        ++i;
    }

    return 0;
}