#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n,a,b; cin >> n >> a >> b;
    int dai = 0, chu = 0, sho=0;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(p <= a) sho++;
        else if(p <= b) chu++;
        else dai++;
    }
    cout << min(dai, min(chu, sho)) << endl;
    return 0;
}