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

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void printAnswer(int index_a, int index_b){
    cout << index_a+1 << " " << index_b+1 << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    int N;
    cin >> N;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    ll min_val = A[0];
    ll min_val_index = 0;
    ll max_val = A[0];
    ll max_val_index = 0;

    FOR(i, 0, N){
        ll val = A[i];
        if(val > max_val){
            max_val = val;
            max_val_index = i;
        }
        else if(val < min_val){
            min_val = val;
            min_val_index = i;
        }
    }

    bool isAllPlus;
    if(abs(max_val)>=abs(min_val)){
        // N回で全てを + にする
        isAllPlus = true;
    }else{
        // N回で全てを - にする
        isAllPlus = false;
    }

    ll orderNum = N + (N-1);
    p(orderNum);

    FOR(i, 0, N){
        if(isAllPlus){
            A[i] += A[max_val_index];
            printAnswer(max_val_index, i);
        }else{
            A[i] += A[min_val_index];
            printAnswer(min_val_index, i);
        }
    }

    if(A[0]>=0){
        // 累積
        FOR(i, 1, N){
            A[i] += A[i-1];
            printAnswer(i-1, i);
        }
    }else{
        // 逆累積
        for(int i=N-2; i>=0; i--){
            A[i] += A[i+1];
            printAnswer(i+1, i);
        }
    }

    // p("check");
    // for(auto a : A){
    //     cout << a << " ";
    // }
    // cout << endl;
    
    return 0;
}