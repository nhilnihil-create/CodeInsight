#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S[i + 1] = S[i] + a;
    }
    
    int left = 1, right = 3;
    long long ans = 1e15;
    for (int mid = 2; mid < N - 1; mid++) {
        long long half = S[mid];
        
        while (S[left] + S[left + 1] < half) left++;
        long long lmin = min(S[left], half - S[left]), lmax = max(S[left], half - S[left]);
        
        while (S[right] + S[right + 1] < S[N] + S[mid]) right++;
        long long rmin = min(S[right] - S[mid], S[N] - S[right]), rmax = max(S[right] - S[mid], S[N] - S[right]);
        
        ans = min(ans, max(rmax, lmax) - min(rmin, lmin));
    }
    cout << ans << endl;
}