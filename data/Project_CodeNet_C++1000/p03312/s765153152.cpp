#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

long long A[200000];
long long cum_sumA[200000];

int calc_boundary(int begin, int end){
    //前半の和が後半の和未満になるもの内前半の和が最大となる分け方の後半の最初のインデックスを返す
    int left = begin;
    int right = end;
    long long begin_base;
    if(begin == 0){
        begin_base = 0;
    } else {
        begin_base = cum_sumA[begin - 1];
    }

    if(A[right] > cum_sumA[right - 1] - begin_base){
        //rightが答え
        return right;
    }
    while(left + 1 < right){
        int next = (left + right) / 2;
        if(cum_sumA[next - 1] - begin_base < cum_sumA[end] - cum_sumA[next - 1]){
            left = next;
        } else {
            right = next;
        }
    }
    return left;
}

void set_sums(long long &P, long long &Q, int begin, int end, int boundary){
    long long begin_base;
    if(begin <= 0){
        begin_base = 0;
    } else {
        begin_base = cum_sumA[begin - 1];
    }
    long long first_P;
    long long first_Q;

    long long first_diff = LLONG_MAX;
    if(boundary > begin){
        first_P = cum_sumA[boundary - 1] - begin_base;
        first_Q = cum_sumA[end] - cum_sumA[boundary - 1];
        first_diff = max(first_P, first_Q) - min(first_P, first_Q);
    }

    long long second_P;
    long long second_Q;

    long long second_diff = LLONG_MAX;
    if(boundary + 1 <= end){
        second_P = cum_sumA[boundary] - begin_base;
        second_Q = cum_sumA[end] - cum_sumA[boundary];
        second_diff = max(second_P, second_Q) - min(second_P, second_Q);
    }

    if(first_diff > second_diff){
        P = second_P;
        Q = second_Q;
    } else {
        P = first_P;
        Q = first_Q;
    }

    return;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cum_sumA[0] = A[0];
    for(int i = 1; i < N; i++){
        cum_sumA[i] = A[i] + cum_sumA[i - 1];
    }

    long long ans = LLONG_MAX;
    for(int i = 2; i < N - 1; i++){
        int PQ_boundary = calc_boundary(0, i - 1);
        int RS_boundary = calc_boundary(i, N - 1);

        long long P;
        long long Q;
        long long R;
        long long S;

        set_sums(P, Q, 0, i - 1, PQ_boundary);
        //cout << P << " " << Q << " " << 0 << " " << i - 1 << " " << PQ_boundary << endl;
        set_sums(R, S, i, N - 1, RS_boundary);

        //cout << i << endl;
        //cout << P << " " << Q << " " << R << " " << S << endl;
        //cout << PQ_boundary << " " << RS_boundary << endl;
        ans = min(ans, max(P, max(Q, max(R, S))) - min(P, min(Q, min(R, S))));
    }

    cout << ans << endl;
    return 0;
}
