#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upper_bound(const vector<int>& array, int v)
{
    int l = 0, r = array.size();
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(array[mid] <= v)
        {
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return r;
}


int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    vector<long long> AB(N), BC(N);
    for(int i=0;i<N;++i) cin >> A[i];
    for(int i=0;i<N;++i) cin >> B[i];
    for(int i=0;i<N;++i) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long long ans = 0;
    for(int i=0;i<N;++i) BC[i] = N - upper_bound(C, B[i]);
    for(int i=N-2;i>=0;--i){
        BC[i] += BC[i+1];
    }

    for(int i=0;i<N;++i)
    {
        int key = upper_bound(B, A[i]);
        ans += BC[key];
    }
    cout << ans << endl;
}
