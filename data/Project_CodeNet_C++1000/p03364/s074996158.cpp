#include <iostream>
#include<vector>
#define MAX_N 300
using namespace std;

int N;
char S[MAX_N][MAX_N];

int solve() {
vector<int> ks;

for(int k=0; k<N; k++) {
bool sw = true;
for(int i=0; i<N; i++)
for(int j=0; j<N; j++)

if(S[i][j]!=S[(j-k+N)%N][(i+k+N)%N])
sw=false;

if(sw) ks.push_back(k);
}

int res=0;
for(int k : ks)
for(int i=0; i<N; i++)
for(int j=0; j<N; j++)
if((i-j+N)%N==k)
res++;

return res;
}

int main() {
	cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> S[i][j];

    cout << solve() << endl;
	return 0;
}