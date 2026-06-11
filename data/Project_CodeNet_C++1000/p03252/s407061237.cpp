#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
bool Ans = 1;
string S, T;cin >> S >> T;
ll L = S.size(), s_count = 0, t_count = 0;
vector<ll> A(L + 1);vector<ll> B(L + 1);
map<char, ll> s;map<char, ll> t;

rep(i, 0, L)s[S[i]]++;

rep(i, 0, L)t[T[i]]++;

for(auto x : s ){

    s_count++;

    A[x.second]++;

}

for(auto x : t ){

    t_count++;

    B[x.second]++;

}

if(s_count != t_count || A != B)Ans = 0;

if(Ans)cout << "Yes";

else cout << "No";
}