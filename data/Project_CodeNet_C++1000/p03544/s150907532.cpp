#include <bits/stdc++.h>
using namespace std;

int main() {

int N;cin >> N;
vector<int64_t> A(N+1);
  A.at(0)=2;A.at(1)=1;

for (int i;i<N-1;i++){
  A.at(i+2)=A.at(i)+A.at(i+1);
}

cout << A.at(N) << endl;

}