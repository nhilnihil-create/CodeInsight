#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n; cin >> n;
    int b[n], ans[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i < n; i++){
        int ind = 1;
        int w = -1;

        for(int j = 0; j < n; j++){
            if(b[j] != INT_MIN){
                if(b[j] == ind){
                    w = j;
                }
                ind++;
            }
        }

        if(w == -1){cout << -1 << endl; return 0;}
        ans[i] = b[w]; b[w] = INT_MIN;
    }

    for(int i = n-1; i >= 0; i--){
        cout << ans[i] << endl;
    }
    return 0;
}