#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int N,M,X,Y;
cin >> N >> M >> X >> Y;
vector<int> A(N);
vector<int> B(M);
int mini = INF,maxi = -1;
for (int i = 0;i < N;i++) {
    cin >> A.at(i);
    if (A.at(i) > maxi) maxi = A.at(i);
}

for (int i = 0;i < M;i++) {
    cin >> B.at(i);
    if (B.at(i) < mini) mini = B.at(i);
}
bool ans = false;
for (int Z = X+1;Z <= Y;Z++) {
    if (maxi < Z && mini >= Z) {
        ans = true;
    }
    } 

if (ans == true) cout << "No War" << endl;
else cout << "War" << endl;


return 0;
}
