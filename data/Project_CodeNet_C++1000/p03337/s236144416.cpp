#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int a;
    int b;
    int ans_add;
    int ans_sub;
    int ans_mul;
    int ans;

    cin >> a >> b;
    ans_add=a+b;
    ans_sub=a-b;
    ans_mul=a*b;
    if(ans_add>ans_sub){
        ans=ans_add;
    }else{
        ans=ans_sub;
    }
    if(ans_mul>ans){
        ans=ans_mul;
    }

    cout << ans << endl;

    return 0;
}
