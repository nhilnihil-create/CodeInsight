#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define int long long
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N;
    cin >> N;
    vector<int> A(N);
    readvec(A);

    int absmax = 0, sign = 1, ind = 0;

    REP(i, N){
        if(llabs(A[i]) > absmax){
            absmax = llabs(A[i]);
            sign = absmax / A[i];
            ind = i;
        }
    }

    cout << 2 * N - 1 << endl;
    //Aの符号を全てsignにする
    REP(i, N){
        cout << ind + 1 << " " << i + 1 << endl;
    }
    if(sign == 1){
        REP(i, N - 1){
            cout << i + 1 << " " << i + 2;
            if(i != N - 2) cout << endl;
        }
    }else{
        REP(i, N - 1){
            cout << N - i << " " << N - i - 1;
            if(i != N - 2) cout << endl;
        }
    }
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}