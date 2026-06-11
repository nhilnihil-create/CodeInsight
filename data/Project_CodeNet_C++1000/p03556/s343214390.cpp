#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,i,sq,end;
    sq = 0;

    cin >> n;
    end = floor(sqrt(n));

    for(i=1; i*i <= n; i++){
        sq = i*i;
    }
    cout << sq << endl;
    return 0;
}