#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, A[100001], B[100001], i, oversum=0, lsum=0, ans=0, sum=0;
    vector<ll> over;

    cin >> N;

    for(i=1; i<=N; i++){
        cin >> A[i];
    }
    for(i=1; i<=N; i++){
        cin >> B[i];

        if(A[i] > B[i]){
            oversum += (A[i]-B[i]);
            over.push_back(A[i]-B[i]);
        }

        else if(A[i] < B[i]){
            lsum += (B[i]-A[i]);
            ans++;
        } 
    }

    sort(over.begin(), over.end());
    reverse(over.begin(), over.end());

    if(lsum > oversum){
        cout << -1 << endl;
    }

    else{
        i = 0;
        while(sum < lsum){
            sum += over.at(i);
            i++;
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}