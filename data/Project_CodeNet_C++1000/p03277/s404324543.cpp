#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int a[101000];

#define MAX_N 250002

ll bit[MAX_N+1];

void init(int n){
    for(int i = 0; i < n; i++){
        bit[i] = 0;
    }
}

// indexが0~iまでの和を求める。
ll sum(int i){
    i++;
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & (-i);
    }
    return s;
}

// iがindex, xが加える値, nが全体の配列の大きさ
void add(int i, ll x, int n){
    i++;
    while(i <= n){
        bit[i] += x;
        i += i & (-i);
    }
}

int b[100100];
map<int, int> m;

int main(){
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+N);
    m[b[0]] = 0;
    int ind = 1;
    for(int i = 1; i < N; i++){
        if(b[i] == b[i-1]){
            continue;
        }
        else{
            m[b[i]] = ind;
            ind++;
        }
    }

    ll l = 0, r = N;
    while(r - l > 1){
        int mid = (l + r) / 2;
        int x = b[mid];
        int s[100100];
        fill(s, s+N, 0);
        for(int i = 0; i < N; i++){
            if(a[i] >= x){
                s[i+1] = 1;
            }
            else{
                s[i+1] = -1;
            }
        }
        for(int i = 1; i <= N; i++){
            s[i] += s[i-1];
        }
        ll res = 0;
        init(2*N+10);
        for(int i = 0; i <= N; i++){
            res += sum(s[i]+N);
            add(s[i]+N, 1, 2*N);
        }
        if(res >= (N*(N+1)/2+1)/2){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    cout << b[l] << endl;


    return 0;

}
