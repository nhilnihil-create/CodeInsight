#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, P;
    cin >> N >> P;

    ll answer = 1;

    // 素因数分解 (factoring)
    FOR(i, 2, sqrt(P)+1){

        int count = 0;
        while(P % i == 0){
            // cout << i << "で割れました" << endl;
            count++;
            P /= i;
        }
        int n = floor(count / N);
        if(n>0){
            answer *= pow(i, n);
        }
    }

    // 割っていった残りも素因数である
    int n = floor(1/N);
    if(n>0){
        answer *= pow(P, n);
    }
    
    p(answer);
    return 0;
}