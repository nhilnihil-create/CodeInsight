#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
int N; cin >> N; char S; string ans="Three";
REP(i, N){ cin >> S; if(S=='Y'){ ans="Four"; } }
cout << ans << "\n";
}