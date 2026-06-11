#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int n, y;
    cin >> n >> y;
    for(int i=0;i<=n;i++){
        for(int j=n-i;j>=0;j--){
            if(10000*i+5000*j+1000*(n-i-j)==y){
                cout << i << " " << j << " " << n-i-j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}