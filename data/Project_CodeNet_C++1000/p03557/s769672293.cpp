#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>

// tgt より低い要素数を返す
// (例) tgt = 4, list = [0, 1, 2, 3, 4, 5]ならば、4を返す
long long bs_lower(long long tgt, const vector<long long> &list){

    long long left=0, right=list.size();
    long long mid = 0;
    
    while(left<right){
        mid = (left+right)/2;
        if(list[mid]<tgt) left = mid+1;
        if(list[mid]>=tgt) right = mid;
    }

    return (left+right)/2;

}

// tgtより高い要素数を返す
// (例)tgt = 4, list = [0, 1, 2, 3, 4, 5]ならば、1を返す。
long long bs_upper(long long tgt, const vector<long long> &list){
    
    long long left=0, right=list.size();
    long long mid = 0;

    while(left<right){
        mid = (left+right)/2;
        if(list[mid]>tgt) left = mid+1;
        if(list[mid]<=tgt) right = mid;
    }
    return (left+right)/2;

}

int main(){

    // test
    // vector<long long> M{0, 1, 2, 3, 4, 4, 5};
    // cout << bs_lower(6, M) << endl;

    // O(N)
    long long N; cin>>N;
    vector<long long> A(N), B(N), C(N);
    for (long long n=0; n<N; n++) cin>>A[n];
    for (long long n=0; n<N; n++) cin>>B[n];
    for (long long n=0; n<N; n++) cin>>C[n];

    // O(NlogN)
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    // O(N) * O(logN)
    long long ans = 0;
    for (long long n=0; n<N; n++){
        
        long long A_lower = bs_lower(B[n], A);
        long long C_upper = bs_upper(B[n], C);

        ans += A_lower * C_upper;

    }

    cout<<ans<<endl;
    
}