#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };




int main() {
    int N;
    cin >> N;
    vi C(N - 1);
    vi S(N - 1);
    vi F(N - 1);
    rep(i, N - 1) {
        cin >> C[i];
        cin >> S[i];
        cin >> F[i];
    }
    for (int i = 0; i < N; i++){
        int t = 0;
        for (int j = i; j < N - 1; j++)
        {
            if (t < S[j]) t = S[j];
            else if (t % F[j] == 0);
            else t = t + F[j] - t % F[j];
            t += C[j];
        }
        cout << t << endl;
    }
}