#include <iostream>
#include <vector>
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

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

vector<bool> is_prime(MAX, true);
vector<LL> prime_list;

void eratos(){
    is_prime[0]=false;
    is_prime[1]=false;
    for(LL i=2; i<MAX; i++){
        if(is_prime[i]==true){
            LL j=i+i;
            while(j<=MAX){
                is_prime[j]=false;
                j=j+i;
            }
            if(i%5==1){
                prime_list.push_back(i);
            }
        }
    }
}

int main(){
    LL n;
    cin >> n;

    eratos();
    for(LL i=0; i<n; i++){
        cout << prime_list[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
