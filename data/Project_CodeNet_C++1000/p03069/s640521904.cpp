#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int N;cin >> N;
  string S; cin>>S;
  int siro[N+1];
  int kuro[N+1];
  int num_kuro = 0;
  int num_siro = 0;
  kuro[0] = 0;
  siro[N] = 0;
  rep(i, N+1){
    if (S[i] == '#') num_kuro++;
    if (S[N-1-i] == '.') num_siro++;
    kuro[i+1] = num_kuro;
    siro[N-1-i] = num_siro;
  }
  int ans = N*10;
  rep(i, N+1){
    //cout << kuro[i] << " " <<siro[i] <<endl; 
    ans = min(ans, kuro[i] + siro[i]);
  }
  cout << ans <<endl;
}