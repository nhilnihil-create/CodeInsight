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
    ll A[N];
    ll B[N+1];
    ll i;
    B[0]=0;
    for(i=0;i<N;i++){
        cin >> A[i];
        B[i+1]=0;
    }
    ll t=0;
    for(i=0;i<N;i++){
        B[A[i]]=B[A[i]-1]+1;
        t=max(t,B[A[i]]);
    }
    cout << N-t;
    return 0;
}
