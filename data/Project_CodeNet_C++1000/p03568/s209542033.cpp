#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll i;
    ll tmp=1,A;
    for(i=0;i<N;i++){
        cin >> A;
        if(A%2==0)tmp*=2;
    }
    cout << pow(3,N)-tmp;
    return 0;
}