#include<bits/stdc++.h>

using namespace std;

long long arr[100];
const int mod = 1e9 + 7;

int main(){
    int N, diff = 0;
    string S;
    cin >> N;
    cin >> S;
    for(int i=0; i<S.length(); i++){
        arr[S[i] - 96]++;
        if(arr[S[i] - 96] == 1) diff++ ;
    }
    long long ans = 1;
    for(int i=1; i<=26; i++){
        ans*= arr[i] + 1;
        ans = ans % mod;
    }
    cout << ans - 1 << endl;
}