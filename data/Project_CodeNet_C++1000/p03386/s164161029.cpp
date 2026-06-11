#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    int i;
    map<int, int> M;
    for(i=a; i<=(a+k-1); i++){
        if(i>b) return 0;
        else if(M[i]==1) continue;
        else{
            cout << i << "\n";
            M[i]++;
        }
    }
    int j = b-k+1;
    if(j<0){
        return 0;
    }
    else{
        for(i=j; i<=b; i++){
            if(M[i]) continue;
            else{
                cout << i << "\n";
            }
        }
    }
    return 0;
}