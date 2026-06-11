#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
using intpair = pair<int, int>;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    cout << (min(A,B)<C && C<max(A,B) ? "Yes" : "No") << endl;
}