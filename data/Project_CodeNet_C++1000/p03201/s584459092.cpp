#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    vector<bool> used(N, false);
    REP(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());

    long i = pow(2, 30);
    int count = 0;
    while(i > 1){
        int left = 0, right = N-1;
        while(left < right){
            if(A[left] + A[right] > i || used[right]) right--;
            else if(A[left] + A[right] < i || used[left]) left++;
            else{
                count++;
                used[left] = true;
                used[right] = true;
                right--; left++;
            }
        }
        i /= 2;
    }
    cout << count << endl;
}