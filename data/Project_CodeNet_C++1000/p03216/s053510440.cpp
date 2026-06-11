#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<long long, long long> pll;

const int maxQ = 80;

void populateIdx(vector<int>& target, vector<int>& first, vector<int>& second, int modifier) {
  int i = 0;
  int len = second.size();
  for(auto k : first) {
    while(k+modifier > second[i] && i < len) {
      i ++;
    }
    target.push_back(i);
  }
  return;
}

void findTriplets(vector<int>* pos, vector<int>& qs) {
  vector<ll> prefixSum (1, 0);
  int idxB = 0;
  int lenB = pos[1].size();
  ll sum = 0;
  for(int i=0; i<pos[2].size(); i++) {
    while(pos[2][i] > pos[1][idxB] && idxB < lenB) {
      idxB++;
    }
    sum += idxB;
    prefixSum.push_back(sum);
  }

  vector<int> low;
  populateIdx(low, pos[0], pos[2], 0);

  vector<int> high[maxQ];
  for(int q=0; q<qs.size(); q++) {
    populateIdx(high[q], pos[0], pos[2], qs[q]);
  }
  vector<int> offset;
  populateIdx(offset, pos[0], pos[1], 0);


  for(int q=0; q<qs.size(); q++) {
    ll ans = 0;
    for(int i=0; i<pos[0].size(); i++) {
      int h = high[q][i];
      int l = low[i];
      ans += prefixSum[h] - prefixSum[l] - ((long long)offset[i] * (h-l));
    }
    cout << ans << endl;
  }
  return;
}

int main (int argc, char*argv[]) {
  int n, Q;
  string s;
  cin >> n >> s >> Q;
  vector<int> q;
  for(int i=0; i<Q; i++) {
    int z;
    cin >> z;
    q.push_back(z);
  }

  vector<int> pos[3];
  for(int i=0; i<n; i++) {
    if(s[i] == 'D') {
      pos[0].push_back(i);
    } else if (s[i] == 'M') {
      pos[1].push_back(i);
    } else if (s[i] == 'C') {
      pos[2].push_back(i);
    }
  }
  if(pos[0].empty() || pos[1].empty() || pos[2].empty()) {
    cerr << 0 << endl;
  } else {
    findTriplets(pos, q);
  }
  return 0;
}
