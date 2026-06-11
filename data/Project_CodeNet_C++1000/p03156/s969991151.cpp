#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N, A ,B;
    cin >> N >> A >> B;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int uA = 0;
    int AuB = 0;
    int oB = 0;
    rep(i,N){
        if (vec[i] <= A) uA++;
        else if (vec[i] <= B) AuB++;
        else oB++;
    }
    cout << min(uA, min(AuB, oB)) << endl;
}