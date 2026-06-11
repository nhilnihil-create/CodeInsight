#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    ll N, tmp;   cin >> N;
    int keta, m, p;
    p = 0;
    tmp = N;
    for(int i=0; i<18; i++){p+=tmp%10; tmp/=10;}
    for(int i=0; i<18; i++) if(N < pow(10,i)){keta = i; m=N/pow(10,i-1); break;}
    m = m-1 + 9*(keta-1);
    cout << max(p,m) << endl;
}