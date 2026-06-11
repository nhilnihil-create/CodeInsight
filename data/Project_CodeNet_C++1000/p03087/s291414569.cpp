#include <bits/stdc++.h>
using namespace std;
#define logn long
int main() {
   long long N, Q; cin >> N >> Q;
   string S; cin >> S;
   vector<long long>A(S.size() + 1, 0);
   for (long long i = 1; i < S.size(); i++) {
       if (S.at(i - 1) == 'A' && S.at(i) == 'C') A.at(i) = A.at(i - 1) + 1;
       else A.at(i) = A.at(i - 1);
   }
   for (long long i = 0; i < Q; i++) {
       long long a,b;cin>>a>>b;
       cout << A.at(b - 1) - A.at(a - 1) << endl;
   }
}