#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<long long> list;
    long long num,no,adder,fin=0;
    cin >> num >> no >> adder;
    long long sum=adder;
    for (long long i=0; i<no; i++){
      long long a;
      cin >> a;
      list.push_back(a);}
    for (long long t=0; t<num; t++) {
      sum=adder;
      for (long long i=0; i<no; i++){
        long long a;
        cin >> a;
        sum+=a*list[i];}
      if (sum>0){fin++;}}
      cout << fin;}