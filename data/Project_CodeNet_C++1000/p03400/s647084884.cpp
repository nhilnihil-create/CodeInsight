#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(void){
    int N,D,X,ans=0;
    cin >> N >> D >> X;
    int n;
    for(int i=0;i<N;i++){
        cin >> n;
        ans += (D-1)/n;
    }
    cout << ans+X+N << endl;
	return 0;
}