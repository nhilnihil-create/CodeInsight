#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    for(int i = A; i <= B; i++){
        if((i >= A && i < A + K) || (i <= B && i > B - K)){
            cout << i << endl;
        }
    }
    return 0;
}