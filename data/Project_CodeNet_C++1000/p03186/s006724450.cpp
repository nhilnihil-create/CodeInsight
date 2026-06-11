#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;


int main() {

    int i=0;
    int A,B,C;
    cin >> A >> B >> C;
    int ans = 0;
    if(C -(A+B+1)>=0){
        ans = A + B*2+1;
    }else{
        ans = B + C;
    }

    cout << ans << endl;
    return 0;
}