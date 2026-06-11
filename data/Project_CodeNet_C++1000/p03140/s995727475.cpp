#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
int main() {
  int N;
  string A,B,C;
  cin >> N >> A >> B >> C;
  int sum = 0;
  for (int i=0; i<N; i++) {
    int cnt = 0;
    if (A[i]==B[i]) cnt--;
    else if(A[i]!=B[i]) cnt++;
    if (B[i]==C[i]) cnt--;
    else if(B[i]!=C[i]) cnt++;
    if (A[i]==C[i]) cnt--;
    else if(A[i]!=C[i]) cnt++;
    if (cnt == 3) cnt = 2;
    cnt = max(0,cnt);
    sum += cnt;
  }
  cout << sum << endl;
}