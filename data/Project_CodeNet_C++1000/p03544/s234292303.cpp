#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long Li=1,Li1=1,Li2=2;
    for(int i=2; i<N+1; i++){
        Li=Li1+Li2;
        Li2=Li1;
        Li1=Li;
    }
    cout << Li << endl;
}
