#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

int main(){
    int N; string S;
    cin >> N >> S;
    int left_black = 0, right_white = 0;
    rep(i,N) if(S[i]=='.') right_white++;
    
    int minimum = right_white;
    rep(i,N){
        if(S[i]=='.') right_white--;
        if(S[i]=='#') left_black++;
        minimum = min(minimum, left_black + right_white);
    }
    cout << minimum << endl;
}