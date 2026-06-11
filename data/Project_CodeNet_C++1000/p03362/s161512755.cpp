#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<char> prime (55556, true);
    prime[0] = prime[1] = false;
    for (long long i=2; i<= 55555; ++i)
        if (prime[i])
            if (i * i <= 55555)
                for (int j=i*i; j<=55555; j+=i)
                    prime[j] = false;
    
    int cnt = 0;
    for(int i = 2; i <= 55555; ++i){
        if(prime[i] && i % 5 == 1){
            cout << i << " ";
            cnt++;
        }
        if(cnt == n) return 0;
    }
}