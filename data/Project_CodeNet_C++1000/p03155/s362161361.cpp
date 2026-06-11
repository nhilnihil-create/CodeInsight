#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <iomanip>
#include <utility>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)
#define ld long double
#define ll long long

using namespace std;

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;


int main(){
  int N;
  int H,W;
  cin >> N >> H >> W;
  cout << (N-H+1)*(N-W+1) << endl;
    return 0;
}
